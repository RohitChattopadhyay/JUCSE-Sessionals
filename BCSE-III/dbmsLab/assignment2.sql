SELECT   MAX(BASIC),   MIN(BASIC),   AVG(BASIC), DEPT_CODE FROM EMP_73 GROUP BY   DEPT_CODE;
-- DEPT_ MAX(BASIC) MIN(BASIC) AVG(BASIC)
-- ----- ---------- ---------- ----------
-- dept1      55000          0 26666.6667
-- dept0     125000          0      62500
-- dept2     255000      75000     165000

SELECT DEPT_CODE,COUNT(*) FROM EMP_73 WHERE SEX='F' GROUP BY DEPT_CODE;
-- DEPT_   COUNT(*)
-- ----- ----------
-- dept2          1

SELECT DEPT_CODE, CITY,   COUNT(*) FROM   EMP_73 GROUP BY   CITY,   DEPT_CODE;
-- DEPT_ CITY                   COUNT(*)
-- ----- -------------------- ----------
-- dept2 KOLKATA                       2
-- dept1 KOLKATA                       3
-- dept0 KOLKATA                       2

SELECT DEPT_CODE, DESIG_CODE,COUNT(*) Count FROM EMP_73 WHERE  to_char(JN_DT,'yyyy') = '2000' GROUP BY DEPT_CODE,DESIG_CODE ORDER BY Count;
-- no rows selected

SELECT DEPT_CODE, SUM(BASIC) TBasic FROM EMP_73 WHERE  SEX = 'M' GROUP BY DEPT_CODE HAVING SUM(BASIC)>50000 ORDER BY TBasic DESC;

SELECT EMP_NAME, DESIG_DESC, BASIC FROM EMP_73, DESIGNATION_73 WHERE EMP_73.DESIG_CODE = DESIGNATION_73.DESIG_CODE;
-- EMP_NAME             DESIG_DESC                BASIC
-- -------------------- -------------------- ----------
-- Garga                Manager                       0
-- Bikshan              Officer                       0
-- Arpan Basu           Executive                 25000
-- Abhay                Officer                   55000
-- Rajdeep              Officer                   75000
-- Dibyajyoti           Clerk                    125000
-- Priti                Manager                  255000

-- 7 rows selected.
SELECT   EMP_NAME,   DESIG_DESC,   DEPT_NAME,   BASIC FROM   EMP_73,   DESIGNATION_73,   DEPARTMENT_73 WHERE   EMP_73.DESIG_CODE = DESIGNATION_73.DESIG_CODE    AND EMP_73.DEPT_CODE = DEPARTMENT_73.DEPT_CODE;

-- EMP_NAME             DESIG_DESC           DEPT_NAME            BASIC
-- -------------------- -------------------- --------------- ----------
-- Garga                Manager              Production               0
-- Bikshan              Officer              Personnel                0
-- Arpan Basu           Executive            Production           25000
-- Abhay                Officer              Production           55000
-- Rajdeep              Officer              Purchase             75000
-- Dibyajyoti           Clerk                Personnel           125000
-- Priti                Manager              Purchase            255000

-- 7 rows selected.

SELECT DEPT_CODE FROM DEPARTMENT_73 WHERE NOT EXISTS  ( SELECT  *  FROM  EMP_73 WHERE EMP_73.DEPT_CODE = DEPARTMENT_73.DEPT_CODE );

-- DEPT_
-- -----
-- dept4
-- dept3

-- 9
SELECT DEPT_NAME FROM DEPARTMENT_73 WHERE EXISTS  ( SELECT  *  FROM  EMP_73 WHERE EMP_73.DEPT_CODE = DEPARTMENT_73.DEPT_CODE );
-- DEPT_NAME
-- ---------------
-- Production
-- Personnel
-- Purchase

--10
SELECT DEPARTMENT_73.DEPT_NAME FROM DEPARTMENT_73, EMP_73 WHERE DEPARTMENT_73.DEPT_CODE=EMP_73.DEPT_CODE GROUP BY DEPARTMENT_73.DEPT_NAME HAVING Count(*) >=10;

--11
SELECT DEPT_CODE FROM   EMP_73 WHERE  EMP_73.BASIC IN ( SELECT Max(BASIC) FROM   EMP_73);

-- DEPT_
-- -----
-- dept2

--12
SELECT DESIG_DESC FROM   EMP_73 NATURAL join   DESIGNATION_73 WHERE  BASIC IN ( SELECT Max(BASIC) FROM   EMP_73 );
-- DESIG_DESC
-- --------------------
-- Manager

--13
SELECT   DEPT_CODE, Count(*) FROM   EMP_73 WHERE    DESIG_CODE='desg0' GROUP BY DEPT_CODE;

--14
SELECT BASIC FROM EMP_73 WHERE  BASIC NOT IN ( SELECT A.BASIC FROM   EMP_73 A, EMP_73 B WHERE  A.BASIC<B.BASIC ) AND ROWNUM<2;
--      BASIC
-- ----------
--     255000

--15
SELECT BASIC FROM EMP_73 WHERE BASIC NOT IN ( SELECT A.BASIC FROM   EMP_73 A, EMP_73 B WHERE  A.BASIC>B.BASIC ) AND ROWNUM<2;

--16
SELECT DEPT_NAME FROM   DEPARTMENT_73 WHERE  DEPT_CODE IN ( SELECT DEPT_CODE FROM   ( SELECT   DEPT_CODE , SUM(BASIC) AS BSUM FROM     EMP_73 GROUP BY DEPT_CODE ) A WHERE  BSUM = ( SELECT   Max(SUM(BASIC)) FROM     EMP_73 GROUP BY DEPT_CODE ) ) ;
-- DEPT_NAME
-- ---------------
-- Purchase

SELECT DEPT_NAME FROM   DEPARTMENT_73 WHERE  DEPT_CODE IN ( SELECT DEPT_CODE FROM   ( SELECT   DEPT_CODE , AVG(BASIC) AS BAVG FROM     EMP_73 GROUP BY DEPT_CODE ) A WHERE  BAVG = ( SELECT   Max(AVG(BASIC)) FROM     EMP_73 GROUP BY DEPT_CODE ) ) ;
-- DEPT_NAME
-- ---------------
-- Purchase

SELECT DEPT_NAME FROM   DEPARTMENT_73 WHERE  DEPT_CODE IN ( SELECT DEPT_CODE FROM   ( SELECT   DEPT_CODE , Count(*) AS CNT FROM     EMP_73 GROUP BY DEPT_CODE ) A WHERE  CNT = ( SELECT   Max(Count(*)) FROM     EMP_73 GROUP BY DEPT_CODE ) ) ;
-- DEPT_NAME
-- ---------------
-- Production

--17
-- TODO

--18
DELETE FROM   EMP_73 WHERE  DESIG_CODE NOT IN ( SELECT DESIG_CODE FROM   DESIGNATION_73 );

--19
SELECT EMP_NAME FROM EMP_73 A WHERE SEX='F' AND BASIC>(SELECT AVG(BASIC) FROM  EMP_73 B GROUP BY B.DEPT_CODE HAVING B.DEPT_CODE = A.DEPT_CODE );
-- EMP_NAME
-- --------------------
-- Priti

--20
SELECT COUNT(*) FROM EMP_73  WHERE SEX='F' AND DESIG_CODE = 'desg0';
--   COUNT(*)
-- ----------
--          1
