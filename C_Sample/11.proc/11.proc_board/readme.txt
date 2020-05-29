DROP TABLE zcube_board;

CREATE TABLE zcube_board
(
  seq       NUMBER,
  writer    VARCHAR2(100),
  regno     VARCHAR2(13),
  subject   VARCHAR2(100),
  cnt       NUMBER,
  contents  VARCHAR2(4000),
  wrdate    DATE
);

ALTER TABLE zcube_board ADD CONSTRAINTS pk_zubeboard PRIMARY KEY(seq);

INSERT INTO zcube_board
  SELECT LEVEL
   ,'CUSNM'||LTRIM(TO_CHAR(LEVEL))
   ,'100'||TO_CHAR(LEVEL,'FM0000000000')
   ,'SUBJECT'||LTRIM(TO_CHAR(LEVEL))
   , 1  
   ,'Contents'||LTRIM(TO_CHAR(LEVEL))
   , sysdate
  FROM DUAL
  CONNECT BY LEVEL <= 100;      

COMMIT;


/////////////////////////////////////////////////////////////////////////////////////////
DROP TABLE zcube_board#

CREATE TABLE zcube_board#
(
  seq       NUMBER,
  writer    VARCHAR2(100),
  regno     VARCHAR2(24),
  subject   VARCHAR2(100),
  cnt       NUMBER,
  contents  VARCHAR2(4000),
  wrdate    DATE
)

INSERT INTO zcube_board#
  SELECT LEVEL
   ,'CUSNM'||LTRIM(TO_CHAR(LEVEL))
   ,xx1.enc_varchar2_ins('100'||TO_CHAR(LEVEL,'FM0000000000'), 10, 'JUMIN1')
   ,'SUBJECT'||LTRIM(TO_CHAR(LEVEL))
   , 1  
   ,'Contents'||LTRIM(TO_CHAR(LEVEL))
   , sysdate
  FROM DUAL
  CONNECT BY LEVEL <= 100;      

COMMIT;




