
LANG=ko_KR.UTF-8
LANG=ko_KR
LANG=en_US

DROP TABLE zcube_hangul;

CREATE TABLE zcube_hangul
(
    col_pk          VARCHAR2(15),
    col_varchar2    VARCHAR2(30),
    col_hangul      VARCHAR2(30),
    col_date        DATE
);

INSERT INTO zcube_hangul VALUES('100','Welcome to Real World','웰컴 투 리얼 월드', SYSDATE);

COMMIT;



SELECT name, value$
FROM sys.props$ 
WHERE name = 'NLS_CHARACTERSET'; 

KO16MSWIN949 
AL32UTF8


export NLS_LANG=AMERICAN_AMERICA.KO16KSC5601



select
CONVERT(xx1.dec_varchar2_sel('pPsXM2kEEP3U0k4nnVgqDIzVqQLp5Iv8uAy5rV8YQJA=',10,'AES256'),
'KO16KSC5601', 'AL32UTF8') from dual;



