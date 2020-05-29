/* 2015-12-31 : Bug fixing of getaddrinfo argument. (shostname->sHostname) */
/* 2015-12-15 : Created by sjson for SHINHAN. Ver 2.5-1906-C */
/**********************************************************************************
 * 
 *   This contain new getipfromtty(), getipbyname(), gethostipaddr() .
 *     using getaddrinfo() call instead of gethostbtname() call.
 *
 ***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <utmpx.h>
#include <errno.h>

int	getipfromtty(sTTY, sIP)
char	*sTTY;
char	*sIP;
{
	struct utmpx		utmpxTTY;
	struct	utmpx *utmpxTmp;
	struct hostent		*hostentLocal;
	int 			uf;
	int			nRtn = 0;

	strcpy (utmpxTTY.ut_line, sTTY);

	utmpxTmp = getutxline (&utmpxTTY);
	if (utmpxTmp ==  NULL)  {
		setutxent();
		#ifdef DEBUG
		printf ("INFO:(getipfromtty): reset utx\n");
		#endif
		utmpxTmp = getutxline (&utmpxTTY);
		if (utmpxTmp ==  NULL)  {
			printf ("INFO:(getipfromtty): Failed to get utx from tty [%s]. errno=[%d]\n", sTTY, errno);
			endutxent ();
			return (-1);
 		}
	}

	if (strcmp (utmpxTmp->ut_host, "") != 0) {
		/**************** Change gethostbyname to getaddrinfo 2015-12-14 sjson *****
		hostentLocal = gethostbyname (utmpxTmp->ut_host);
		if (hostentLocal != NULL) {
			struct in_addr in;
			memcpy(&in.s_addr, *(hostentLocal->h_addr_list), sizeof (in.s_addr));
			strcpy (sIP, inet_ntoa(in));
		}
		******************************************************************************/
		    if (getipbyname (utmpxTmp->ut_host, sIP) != 0)
		    {
		        printf ("Error: Fail to get ip [%s]", utmpxTmp->ut_host) ;
		        nRtn = -1 ;
		    }
	}
	endutxent ();
		
	return (nRtn);
}
/* end of getipfromtty(); */

int getipbyname (char *shostname, char *sIP)
{
    struct addrinfo hints;
    struct addrinfo *result, *rp;    
    char buf[80] ;
    char sHostname[256] ;

	if (shostname != NULL && strcmp (shostname, "") != 0) {
		strcpy (sHostname, shostname);
	}
	else {
		if (gethostname (sHostname, 256) < 0) {
		   return (-1);
		}
	}
    memset(&hints, 0x00, sizeof(struct addrinfo));

    hints.ai_flags = AI_CANONNAME;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

/* Wrong Usage. 2015-12-31 sjson Hmmm... ******************
    if(getaddrinfo(shostname, NULL, &hints, &result) != 0 )
***********************************************************/
    if(getaddrinfo(sHostname, NULL, &hints, &result) != 0 )
    {
#ifdef DEBUG
    	printf ("getaddrinfo failed = [%d]\n", errno) ;
#endif
        return -1 ;
    }

    rp = result ;
    memset(buf, 0x00, sizeof(buf));
    if (getnameinfo(rp->ai_addr, rp->ai_addrlen, buf, sizeof(buf), 
    		NULL, 0, NI_NUMERICHOST) != 0)
	{
#ifdef DEBUG
    	printf ("getnameinfo failed = [%d]\n", errno) ;
#endif
	return -2 ;
	}
#ifdef DEBUG
    printf ("Canon Name = [%s]\n", rp->ai_canonname) ;
#endif
    freeaddrinfo(result);

    strcpy (sIP, buf) ;

    return 0 ;
}

int gethostipaddr(char *sHostIP)
{
	return getipbyname ((char *)NULL, sHostIP) ;
}

#ifdef SELFTEST
#ifdef HPUX
#include <sys/pstat.h>
#endif
int main(int argc, char *argv[])
{
	char    *pTTY;
	char AppName[100] ;
	char sIP[100] ;
	char sTTY[100] ;
	int retProc = 0;
#ifdef HPUX
	struct pst_status pst;
	int procId ;
#endif
	/* Normal Code to get TTY num */
	if (isatty(0) == 0) {
		printf ("Warning: This process is not assocated with terminal.\n");
		exit (0) ;
	}
	else {
		pTTY = ttyname(0);
	}

	printf ("TTY Name = [%s]\n", pTTY) ;  /* To test, eliminate /dev heading.... */
	if (strncmp (pTTY, "/dev", 4) == 0) pTTY = pTTY + 5 ;
#ifdef HPUX
	/* Special Code to get TTY num from HP */
	memset (&pst, 0x00, sizeof (struct pst_status));
	procId = atoi(argv[2]) ;
	/*
	retProc = pstat_getproc (&pst, sizeof(pst), (size_t)0, getppid());
	*/
	retProc = pstat_getproc (&pst, sizeof(pst), (size_t)0, procId) ;
	if (retProc != -1) {
		printf ("Major = [%d], Minor = [%d]\n", pst.pst_term.psd_major, pst.pst_term.psd_minor) ;
		sprintf (sTTY, "%d", pst.pst_term.psd_minor) ;
	}

	printf ("TTY Name = [%s] -- [%d]\n", sTTY, procId) ;
#endif	
	if (getipfromtty (pTTY, sIP) != 0)

		getipfromtty (argv[1], sIP) ;

	printf ("IP addr = [%s]\n", sIP) ;

	exit(0) ;
}
#endif /* End of SELFTEST */

