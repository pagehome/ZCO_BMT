#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main (int argc, char* argv[])
{
    printf("########################################################\n");
    printf("#########  CubeOneAPI-C Self Test Program(Father) ######\n");
    printf("########################################################\n\n");

    pid_t pid;
    int nRtn;
    int stat ;

    /* char *exe_argv[] ={ "ls", "-al", "/tmp", NULL}; */
    char *exe_argv[] ={ "co_encsam", "sam.dat", "sam_exec.dat","enc.cfg",NULL};

    /* nRtn = execvp("/usr/bin/ls", NULL); */
    /* nRtn = execvp("ls", exe_argv); */
    /* nRtn = execvp("/data1/cubeapi/bin/cubeoned", exe_argv); */
    /* nRtn = execvp("/home/cubeapi/bin/co_encsam", exe_argv); */

    int i=0;
/*
    for(i=0;i<9;i++) {
*/
    switch (pid = fork()) {
        case -1 : /* fork failed */
            perror("fork");
            exit(1);
            break;
        case 0 : /* child process */
            printf("--> Child Process\n");
            /*nRtn = execvp("co_son", exe_argv); */
            nRtn = execvp("../../../../bin/co_encsam", exe_argv);
            exit(0);
            break;
        default : /* parent process */
            printf("--> Parent process - My PID:%d\n\n",(int)getpid());
            /*wait(&stat) ;*/
            break;
    }
/*
    }
*/

    printf("########################################################\n\n");
    printf("########################################################\n\n");
    printf("\n<<< CubeLog :: with return [%d].\n",nRtn);
}
