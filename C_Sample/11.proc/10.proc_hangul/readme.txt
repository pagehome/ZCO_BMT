#####################################################################
LANG=ko_KR.UTF-8
LANG=ko_KR
LANG=en_US

export NLS_LANG=AMERICAN_AMERICA.KO16KSC5601

#####################################################################

DROP TABLE SCOTT.ZCUBE_HANGUL# CASCADE CONSTRAINTS;

CREATE TABLE SCOTT.ZCUBE_HANGUL#
(
  COL_PK        VARCHAR2(15 BYTE),
  COL_VARCHAR2  VARCHAR2(30 BYTE),
  COL_HANGUL    VARCHAR2(50 BYTE),
  COL_DATE      DATE
)

#####################################################################

DROP TABLE SCOTT.ZCUBE_HANGUL CASCADE CONSTRAINTS;

CREATE TABLE SCOTT.ZCUBE_HANGUL
(
  COL_PK        VARCHAR2(15 BYTE),
  COL_VARCHAR2  VARCHAR2(30 BYTE),
  COL_HANGUL    VARCHAR2(30 BYTE),
  COL_DATE      DATE
)

INSERT INTO zcube_hangul VALUES('100','한글','한글', SYSDATE);

COMMIT;

#####################################################################


SELECT name, value$
FROM sys.props$ 
WHERE name = 'NLS_CHARACTERSET'; 

KO16MSWIN949 
AL32UTF8

#####################################################################




