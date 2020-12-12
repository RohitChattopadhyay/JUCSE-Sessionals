Assignment 4 :  PL/SQL
---
### 1.  GET Employee Name by ID
```sql
DECLARE
    emp_code_res emp.EMP_CODE%type;
    emp_name_res emp.EMP_NAME%type;
BEGIN
    emp_code_res := '&emp_code_res';
    select emp_name into emp_name_res from emp where emp_code=emp_code_res;
    DBMS_OUTPUT.Put_line('NAME of EMPLOYEE with CODE ' || emp_code_res || ' is ' || emp_name_res);
EXCEPTION
    WHEN no_data_found THEN
        DBMS_OUTPUT.Put_line('There is no EMPLOYEE with CODE ' || emp_code_res );
    WHEN others THEN
        DBMS_OUTPUT.Put_line('ERROR!');
END;
```
### 2. ADD Employee to Table
```sql
DECLARE
    emp_code_res emp.EMP_CODE%type;
    emp_name_res emp.EMP_NAME%type;
    emp_dept_res emp.DEPT_CODE%type;
    emp_desig_res emp.DESIG_CODE%type;
    emp_sex_res emp.SEX%type;
    emp_address_res emp.ADDRESS%type;
    emp_city_res emp.CITY%type;
    emp_state_res emp.STATE%type;
    emp_pin_res emp.PIN%type;
    emp_basic_res emp.BASIC%type;
BEGIN
    DBMS_OUTPUT.Put_line('Enter Employee Code: ');
    emp_code_res := '&emp_code_res';
    
    DBMS_OUTPUT.Put_line('Enter Employee Name: ');
    emp_name_res := '&emp_name_res';
    
    DBMS_OUTPUT.Put_line('Enter Department: ');
    emp_dept_res := '&emp_dept_res';
    
    DBMS_OUTPUT.Put_line('Enter Designation: ');
    emp_desig_res := '&emp_desig_res';
    
    DBMS_OUTPUT.Put_line('Enter Employee Gender: ');
    emp_sex_res := '&emp_sex_res';
    
    DBMS_OUTPUT.Put_line('Enter Address: ');
    emp_address_res := '&emp_address_res';
    
    DBMS_OUTPUT.Put_line('Enter City: ');
    emp_city_res := '&emp_city_res';
    
    DBMS_OUTPUT.Put_line('Enter State: ');
    emp_state_res := '&emp_state_res';
    
    DBMS_OUTPUT.Put_line('Enter Pincode: ');
    emp_pin_res := '&emp_pin_res';
    
    DBMS_OUTPUT.Put_line('Enter Basic: ');
    emp_basic_res := '&emp_basic_res';
    
    INSERT into EMP values (emp_code_res, emp_name_res , emp_name_res , emp_desig_res,  emp_sex_res ,  emp_address_res , emp_city_res , emp_state_res , emp_pin_res , emp_basic_res, SYSDATE);
    DBMS_OUTPUT.Put_line('New EMPLOYEE inserted.');
EXCEPTION
    WHEN DUP_VAL_ON_INDEX THEN
        DBMS_OUTPUT.Put_line('ERROR: EMPLOYEE CODE already exists');
    WHEN others THEN
        DBMS_OUTPUT.Put_line('ERROR!');
END;
/
```
### 3. Top 5 BASIC
```sql
DECLARE
    CURSOR emp_cursor IS SELECT * FROM  EMP ORDER BY BASIC DESC; 
    loop_row    emp_cursor%ROWTYPE; 
    counter     INTEGER;
BEGIN
    counter := 0;
    FOR loop_row IN emp_cursor LOOP
        IF counter<5 THEN
		    counter:= counter+1;
            DBMS_OUTPUT.Put_line( loop_row.EMP_CODE || '    ' || loop_row.EMP_NAME || loop_row.BASIC);
        END IF;
    END LOOP;
END ;
```
### 4. DELETE Employees by Department Code
```sql
DECLARE
    dept_code_res DEPARTMENT.DEPT_CODE%type ;
BEGIN
	dept_code_res := '&dept_code_res';
	delete from EMP where dept_code=dept_code;
	DBMS_OUTPUT.Put_line(sql%rowcount || ' rows deleted');
END;
```

### 5. ORDER management
Table Creation
```sql
create table ORDERMAST ( 
    ORDER_NO char(5) constraint ordermast_pk primary key, 
    ORDER_DT date 
);

create table ORDERDETAILS ( 
    ORDER_NO char(5), 
    ITEM_NO char(5), 
    QTY number 
);
alter table ORDERDETAILS add constraint orderdetails_pk primary key (ORDER_NO, ITEM_NO);

create table DELIVERYMAST ( 
    DELV_NO char(5) constraint deliverymast_pk primary key, 
    ORDER_NO char(5), 
    DELV_DT date 
);

create table DELIVER_DETAILS ( 
    DELV_NO char(5), 
    ITEM_NO char(5), 
    QTY number 
);
```
Populating Tables
```sql
INSERT INTO DELIVERYMAST VALUES('D1','O1',SYSDATE);
INSERT INTO DELIVERYMAST VALUES('D2','O1',SYSDATE);
INSERT INTO DELIVER_DETAILS VALUES('D1','T1',5);
INSERT INTO DELIVER_DETAILS VALUES('D2','T2',3);

INSERT INTO ORDERMAST VALUES('O2',SYSDATE) 
INSERT INTO ORDERDETAILS VALUES('O2' , 'T3' , 5) 
INSERT INTO ORDERDETAILS VALUES('O2' , 'T2' , 7) ;
INSERT INTO ORDERMAST VALUES('O2',SYSDATE);
INSERT INTO ORDERDETAILS VALUES('O2' , 'T3' , 5);
INSERT INTO ORDERDETAILS VALUES('O2' , 'T2' , 7);
```
SQL
```sql
select O.ORDER_NO, O.ORDER_DT,O.ITEM_NO,O.QTY-NVL(D.DELIVERED_QTY,0) as PENDING_QTY from 
    (select O1.ORDER_NO, O1.ORDER_DT, ORDERDETAILS.ITEM_NO, ORDERDETAILS.QTY from
        (select ORDER_NO, ORDER_DT from ORDERMAST where ORDER_DT BETWEEN SYSDATE-1 and SYSDATE+1) O1 
        join ORDERDETAILS 
        on O1.ORDER_NO=ORDERDETAILS.ORDER_NO
    ) O
    left join
    (
        select D1.DELV_NO, D1.ORDER_NO, D2.ITEM_NO, D2.QTY as DELIVERED_QTY from DELIVERYMAST D1
        join DELIVER_DETAILS D2 on D1.DELV_NO=D2.DELV_NO
    ) D
on O.ORDER_NO=D.ORDER_NO and O.ITEM_NO=D.ITEM_NO
where delivered_qty is NULL or delivered_qty!=qty
```
PL/SQL
```sql
DECLARE
  date1   DATE;
  date2   DATE;
  input_1 CHAR(10);
  input_2 CHAR(10);
BEGIN
  input_1 := '&INPUT_1';
  date1 := to_date(input_1,'DD/MM/YYYY');
  input_2 := '&INPUT_2';
  date2 := to_date(input_2,'DD/MM/YYYY');
  dbms_output.Put_line('Pending Orders ');
  FOR rec IN
  (
            SELECT    O.order_no,
                      O.order_dt,
                      O.item_no,
                      O.qty-Nvl(D.delivered_qty,0) AS PENDING_QTY
            FROM      (
                             SELECT O1.order_no,
                                    O1.order_dt,
                                    orderdetails.item_no,
                                    orderdetails.qty
                             FROM   (
                                           SELECT order_no,
                                                  order_dt
                                           FROM   ordermast
                                           WHERE  order_dt BETWEEN date1 AND    date2) O1
                             join   orderdetails
                             ON     O1.order_no=orderdetails.order_no ) O
            left join
                      (
                             SELECT D1.delv_no,
                                    D1.order_no,
                                    D2.item_no,
                                    D2.qty AS DELIVERED_QTY
                             FROM   deliverymast D1
                             join   deliver_details D2
                             ON     D1.delv_no=D2.delv_no ) D
            ON        O.order_no=D.order_no
            AND       O.item_no=D.item_no
            WHERE     delivered_qty IS NULL
            OR        delivered_qty!=qty )
  LOOP
    dbms_output.Put_line(rec.ORDER_NO
    || ' '
    || rec.ORDER_DT
    || ' '
    || rec.ITEM_NO
	|| ' '
	|| rec.PENDING_QTY
	);
  END LOOP;
END;
```
Output
```
Pending Orders  
O1 29-SEP-20 T2 4  
O2 29-SEP-20 T3 5  
O2 29-SEP-20 T2 7
```
### 6. LEAVE management
Create Table
```sql
create table LEAVE (
    EMP_NO char(5) constraint leave_pk primary key,
    MONTH number,
    NO_OF_DAYS number
);
```
Create Procedure
```sql
create or replace function DAYS_IN_MONTH (
    month in  number 
) return number
is
    modulo INTEGER;
begin
    modulo := MOD(month,2);
    IF month<1 OR month>12 THEN
        RETURN 0;
    END IF;
    
    IF month=2 THEN
        RETURN 28;
    END IF;
    
    IF month<=7 THEN
        IF modulo=0 THEN
            return 30;
        ELSE
            return 31;
        END IF;
    ELSIF modulo=0 THEN
        return 31;
    ELSE
        return 30;
    END IF;
end DAYS_IN_MONTH;
```
SQL
```sql
select EMP_CODE, EMP_NAME, BASIC*(1 - NVL(NO_OF_DAYS,0)/DAYS_IN_MONTH(MONTH)) as NET_PAY 
from emp left join (select * from leave where month=EXTRACT(MONTH from SYSDATE))
on EMP_CODE = EMP_NO;
```
PL/SQL
```sql
DECLARE
    req_month INTEGER;
BEGIN
    req_month:= EXTRACT(MONTH FROM SYSDATE);
    dbms_output.put_line('Pay Ledger for ' || to_char(SYSDATE,'Month'));
    FOR rec IN (select EMP_CODE,EMP_NAME, BASIC*(1 - NVL(NO_OF_DAYS,0)/DAYS_IN_MONTH(MONTH)) as NET_PAY from emp left join (select * from leave where month=req_month) on EMP_CODE = EMP_NO) LOOP
        dbms_output.put_line(rec.EMP_CODE || ' ' || rec.EMP_NAME || ' ' || rec.NET_PAY);
    END LOOP;
END;
```
Output
```
Pay Ledger for September  
EMP01 Palmer Mcintyre 37500  
EMP02 Elmo Woods 27500  
EMP03 April Gallagher 61500  
EMP04 Tate Ford 66500  
EMP05 Quon Kennedy 29300  
EMP06 Uma Lyons 55600  
EMP07 Avye Kidd 30100  
EMP08 Hoyt Hoffman 28700  
EMP09 Jocelyn Reid 52200  
...
```