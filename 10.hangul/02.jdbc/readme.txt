

LANG=ko_KR.UTF-8

DROP TABLE zcube_hangul;

CREATE TABLE zcube_hangul
(
    col_pk          VARCHAR2(15),
    col_varchar2    VARCHAR2(30),
    col_hangul      VARCHAR2(30),
    col_date        DATE
);

INSERT INTO zcube_hangul VALUES('100','Welcome to Real World','›°ì»´ ˆ ë¦¬ì– ›”“œ', SYSDATE);

COMMIT;



SELECT name, value$
FROM sys.props$ 
WHERE name = 'NLS_CHARACTERSET'; 

KO16MSWIN949 
AL32UTF8



