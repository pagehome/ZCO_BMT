
<< 목적 >>
Data type 별 암복화 sampple


<<




CREATE TABLE SCOTT.ZCUBE_DATATYPE#
(
  COL_PK        VARCHAR2(15 BYTE),
  COL_VARCHAR2  VARCHAR2(4000 BYTE),
  COL_CHAR      VARCHAR2(4000 BYTE),
  COL_NUMBER    VARCHAR2(4000 BYTE),
  COL_DATE      VARCHAR2(4000 BYTE)
)


CREATE TABLE SCOTT.ZCUBE_DATATYPE8
(
  COL_PK        VARCHAR2(15 BYTE),
  COL_VARCHAR2  VARCHAR2(15 BYTE),
  COL_CHAR      CHAR(15 BYTE)                   DEFAULT ' ',
  COL_NUMBER    NUMBER,
  COL_DATE      DATE
)o


INSERT INTO zcube_datatype(col_pk, col_varchar2, col_char, col_number, col_date)
VALUES('100','100','100', 100, SYSDATE);

COMMIT;



