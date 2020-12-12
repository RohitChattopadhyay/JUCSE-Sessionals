Assignment 1 : SQL
---
### 1.  Create Tables
```sql
create table EMP (
    EMP_CODE char(5) constraint emp_pk primary key,
    EMP_NAME char(20),
    DEPT_CODE char(5),
    DESIG_CODE char(5),
    SEX char(1),
    ADDRESS char(25),
    CITY char(20),
    STATE char(20),
    PIN char(6),
    BASIC number,
    JN_DT date
);
```
```sql
create table DESIGNATION (
    DESIG_CODE char(5) constraint designation_pk primary key,
    DESIG_DESC char(20)
);
```
```sql
create table DEPARTMENT (
	DEPT_CODE char(5) constraint department_pk primary key,
	DEPT_NAME char(15)
);
```
### 2. Table Structures
```sql
select COLUMN_NAME, DATA_TYPE, DATA_LENGTH, NULLABLE
from user_tab_columns
where table_name = 'EMP'
```
```
| COLUMN_NAME | DATA_TYPE | DATA_LENGTH | NULLABLE | 
|-------------|-----------|-------------|----------| 
| EMP_CODE    | CHAR      | 5           | N        | 
| EMP_NAME    | CHAR      | 20          | Y        | 
| DEPT_CODE   | CHAR      | 5           | Y        | 
| DESIG_CODE  | CHAR      | 5           | Y        | 
| SEX         | CHAR      | 1           | Y        | 
| ADDRESS     | CHAR      | 25          | Y        | 
| CITY        | CHAR      | 20          | Y        | 
| STATE       | CHAR      | 20          | Y        | 
| PIN         | CHAR      | 6           | Y        | 
| BASIC       | NUMBER    | 22          | Y        | 
| JN_DT       | DATE      | 7           | Y        | 
```
```sql
select COLUMN_NAME, DATA_TYPE, DATA_LENGTH, NULLABLE
from user_tab_columns
where table_name = 'DESIGNATION'
```
```
| COLUMN_NAME | DATA_TYPE | DATA_LENGTH | NULLABLE | 
|-------------|-----------|-------------|----------| 
| DESIG_CODE  | CHAR      | 5           | N        | 
| DESIG_DESC  | CHAR      | 20          | Y        | 
```
```sql
select COLUMN_NAME, DATA_TYPE, DATA_LENGTH, NULLABLE
from user_tab_columns
where table_name = 'DEPARTMENT'
```
```
| COLUMN_NAME | DATA_TYPE | DATA_LENGTH | NULLABLE | 
|-------------|-----------|-------------|----------| 
| DEPT_CODE   | CHAR      | 5           | N        | 
| DEPT_NAME   | CHAR      | 15          | Y        | 
```
### 3. Populate Database
```sql
INSERT INTO DEPARTMENT VALUES('DEPT0', 'Personnel');
INSERT INTO DEPARTMENT VALUES('DEPT1', 'Production');
INSERT INTO DEPARTMENT VALUES('DEPT2', 'Purchase');	
INSERT INTO DEPARTMENT VALUES('DEPT3', 'Finance');	
INSERT INTO DEPARTMENT VALUES('DEPT4', 'Research');

INSERT INTO DESIGNATION VALUES('DESG0', 'Manager');
INSERT INTO DESIGNATION VALUES('DESG1', 'Executive');
INSERT INTO DESIGNATION VALUES('DESG2', 'Officer');
INSERT INTO DESIGNATION VALUES('DESG3', 'Clerk');
INSERT INTO DESIGNATION VALUES('DESG4', 'Helper');
```
```sql
INSERT INTO EMP VALUES('EMP01','Palmer Mcintyre','DEPT0','DESG0','M','859-2809 Integer St.','Pazardzhik','Uttar Pradesh','925464',37500,TO_DATE('43846', 'J'));
INSERT INTO EMP VALUES('EMP02','Elmo Woods','DEPT0','DESG2','M','858-2992 Praesent Rd.','Dimitrovgrad','Andhra Pradesh','491107',27500,TO_DATE('44071', 'J'));
INSERT INTO EMP VALUES('EMP03','April Gallagher','DEPT0','DESG4','M','Ap #246-3775 Mattis. Ave','Gabrovo','Uttar Pradesh','646417',61500,TO_DATE('43931', 'J'));
INSERT INTO EMP VALUES('EMP04','Tate Ford','DEPT4','DESG3','F','489-7202 Pellentesque St.','Gotse Delchev','Tamil Nadu','751365',66500,TO_DATE('44022', 'J'));
INSERT INTO EMP VALUES('EMP05','Quon Kennedy','DEPT2','DESG0','F','198 Nisi Rd.','Kazanlk','Uttar Pradesh','952263',29300,TO_DATE('43851', 'J'));
INSERT INTO EMP VALUES('EMP06','Uma Lyons','DEPT0','DESG0','M','Ap #139-1094 Quis Rd.','Lom','MH','141522',55600,TO_DATE('43961', 'J'));
INSERT INTO EMP VALUES('EMP07','Avye Kidd','DEPT1','DESG3','M','397-581 Augue Rd.','Karlovo','MH','363955',30100,TO_DATE('44049', 'J'));
INSERT INTO EMP VALUES('EMP08','Hoyt Hoffman','DEPT4','DESG0','F','467-2117 Pede. Rd.','Ruse','Uttar Pradesh','764533',28700,TO_DATE('44042', 'J'));
INSERT INTO EMP VALUES('EMP09','Jocelyn Reid','DEPT1','DESG1','F','Ap #788-4304 Vel, Ave','Karnobat','RJ','184410',52200,TO_DATE('44045', 'J'));
INSERT INTO EMP VALUES('EMP10','Gregory Rice','DEPT0','DESG4','M','P.O. Box 992, 9089 Donec St.','Rakovski','Bihar','465926',46800,TO_DATE('43933', 'J'));
INSERT INTO EMP VALUES('EMP11','Peter Chase','DEPT1','DESG0','M','Ap #840-2051 In, Street','Silistra','Madhya Pradesh','929955',37400,TO_DATE('44048', 'J'));
INSERT INTO EMP VALUES('EMP12','Fuller Vargas','DEPT3','DESG3','F','P.O. Box 901, 9501 Dictum Road','Blagoevgrad','CT','390491',65100,TO_DATE('44069', 'J'));
INSERT INTO EMP VALUES('EMP13','Pamela Hart','DEPT2','DESG3','M','976-9658 Felis St.','Aytos','Bihar','590640',44300,TO_DATE('44019', 'J'));
INSERT INTO EMP VALUES('EMP14','Christine Calderon','DEPT2','DESG3','M','821-2392 Odio Rd.','Karlovo','Maharastra','704473',26700,TO_DATE('44093', 'J'));
INSERT INTO EMP VALUES('EMP15','Hunter York','DEPT0','DESG4','F','P.O. Box 544, 576 Sit Street','Karlovo','MP','391346',68800,TO_DATE('44087', 'J'));
INSERT INTO EMP VALUES('EMP16','Fuller Reese','DEPT3','DESG1','F','Ap #388-2903 Donec St.','Sevlievo','Uttar Pradesh','711768',32400,TO_DATE('43836', 'J'));
INSERT INTO EMP VALUES('EMP17','Howard Carter','DEPT0','DESG1','F','P.O. Box 372, 3840 Sagittis Av.','Shumen','Chhattisgarh','174993',39400,TO_DATE('43924', 'J'));
INSERT INTO EMP VALUES('EMP18','Idona Page','DEPT4','DESG1','F','7888 Ipsum Avenue','Haskovo','CH','814022',54700,TO_DATE('43840', 'J'));
INSERT INTO EMP VALUES('EMP19','Austin Gamble','DEPT4','DESG1','M','6438 Quisque St.','Plovdiv','WB','352871',25300,TO_DATE('43919', 'J'));
INSERT INTO EMP VALUES('EMP20','Dustin Huff','DEPT0','DESG2','F','1949 Tristique Ave','Panagyurishte','WB','325139',50600,TO_DATE('43987', 'J'));
INSERT INTO EMP VALUES('EMP21','Jeremy Caldwell','DEPT2','DESG4','F','P.O. Box 811, 5429 Luctus Avenue','Sandanski','West Bengal','645339',37900,TO_DATE('44076', 'J'));
INSERT INTO EMP VALUES('EMP22','Oprah Spence','DEPT3','DESG0','F','Ap #178-9406 Ligula. St.','Smolyan','Andhra Pradesh','561889',41900,TO_DATE('44048', 'J'));
INSERT INTO EMP VALUES('EMP23','Elizabeth Ellis','DEPT1','DESG0','M','1579 Ac Rd.','Botevgrad','UT','560360',29900,TO_DATE('44038', 'J'));
INSERT INTO EMP VALUES('EMP24','Peter Hansen','DEPT3','DESG4','F','P.O. Box 380, 885 Mollis St.','Petrich','KA','889566',71400,TO_DATE('44016', 'J'));
INSERT INTO EMP VALUES('EMP25','Kameko Robles','DEPT0','DESG4','F','344-481 Cras Ave','Montana','MH','537696',27400,TO_DATE('43861', 'J'));
INSERT INTO EMP VALUES('EMP26','Cheryl Willis','DEPT2','DESG0','F','444-8761 Nibh. Street','Lovech','West Bengal','396393',56000,TO_DATE('43947', 'J'));
INSERT INTO EMP VALUES('EMP27','Branden Hutchinson','DEPT4','DESG3','M','Ap #140-3891 Interdum. St.','Pernik','RJ','625745',62100,TO_DATE('43985', 'J'));
INSERT INTO EMP VALUES('EMP28','Rhona Reyes','DEPT2','DESG0','F','P.O. Box 732, 4027 Lectus Road','Chirpan','MP','745980',38100,TO_DATE('44084', 'J'));
INSERT INTO EMP VALUES('EMP29','Iliana Dennis','DEPT2','DESG2','M','1818 Purus Avenue','Montana','KA','351744',60300,TO_DATE('43877', 'J'));
INSERT INTO EMP VALUES('EMP30','Benedict Callahan','DEPT2','DESG4','F','370-5277 Magnis St.','Sandanski','Karnataka','546943',51400,TO_DATE('43953', 'J'));
INSERT INTO EMP VALUES('EMP31','Georgia Warren','DEPT0','DESG4','M','377-1881 Nunc Rd.','Burgas','Uttar Pradesh','981676',54700,TO_DATE('43999', 'J'));
INSERT INTO EMP VALUES('EMP32','Kathleen Walker','DEPT4','DESG0','M','884-7192 Facilisis Avenue','Svilengrad','Punjab','623217',29800,TO_DATE('43982', 'J'));
INSERT INTO EMP VALUES('EMP33','Constance Pratt','DEPT1','DESG3','F','Ap #373-7219 Etiam St.','Samokov','Rajasthan','522506',47400,TO_DATE('43991', 'J'));
INSERT INTO EMP VALUES('EMP34','Halee Hamilton','DEPT4','DESG0','M','720-9156 Leo. St.','Berkovitsa','TN','282580',74000,TO_DATE('44043', 'J'));
INSERT INTO EMP VALUES('EMP35','Leslie Berg','DEPT3','DESG2','M','6312 Facilisis St.','Aytos','West Bengal','877530',71000,TO_DATE('43841', 'J'));
INSERT INTO EMP VALUES('EMP36','Xenos Day','DEPT2','DESG3','M','480 Dignissim Ave','Popovo','AR','381117',26000,TO_DATE('43850', 'J'));
INSERT INTO EMP VALUES('EMP37','Mira Brown','DEPT1','DESG4','F','P.O. Box 753, 1510 Nisi. Street','Kharmanli','Uttar Pradesh','782304',55200,TO_DATE('43907', 'J'));
INSERT INTO EMP VALUES('EMP38','Brody Lott','DEPT3','DESG4','M','353-7366 Ornare, Ave','Botevgrad','BR','122735',33100,TO_DATE('43988', 'J'));
INSERT INTO EMP VALUES('EMP39','Jessamine Fitzgerald','DEPT4','DESG4','F','Ap #814-2190 Libero. Ave','Gorna Oryakhovitsa','Uttar Pradesh','272513',61800,TO_DATE('44011', 'J'));
INSERT INTO EMP VALUES('EMP40','Coby Floyd','DEPT4','DESG3','M','4898 Ac Ave','Popovo','RJ','754351',42400,TO_DATE('43915', 'J'));
INSERT INTO EMP VALUES('EMP41','Wayne Stephenson','DEPT4','DESG3','M','7748 Quis, Road','Sevlievo','GJ','964726',47200,TO_DATE('44084', 'J'));
INSERT INTO EMP VALUES('EMP42','Roanna Dixon','DEPT4','DESG3','F','Ap #563-4770 Non St.','Cherven Bryag','MP','759299',74300,TO_DATE('43871', 'J'));
INSERT INTO EMP VALUES('EMP43','Lamar Solomon','DEPT3','DESG4','M','P.O. Box 461, 6140 Quis Street','Petrich','Jharkhand','844288',39300,TO_DATE('44013', 'J'));
INSERT INTO EMP VALUES('EMP44','Ursula Bates','DEPT1','DESG3','M','291-9147 Vitae Street','Sliven','MP','610113',60900,TO_DATE('43960', 'J'));
INSERT INTO EMP VALUES('EMP45','Cathleen Walker','DEPT3','DESG0','F','Ap #861-6789 Lectus Avenue','Dupnitsa','West Bengal','787737',38000,TO_DATE('44088', 'J'));
INSERT INTO EMP VALUES('EMP46','Bradley Joseph','DEPT4','DESG2','M','101-9755 Metus. St.','Pazardzhik','Uttar Pradesh','219229',58300,TO_DATE('43936', 'J'));
INSERT INTO EMP VALUES('EMP47','Mariam Wooten','DEPT2','DESG0','F','7391 Cum St.','Kyustendil','OR','566619',40600,TO_DATE('44060', 'J'));
INSERT INTO EMP VALUES('EMP48','Drew Gay','DEPT1','DESG4','F','Ap #872-1452 Curabitur Street','Razgrad','Andhra Pradesh','493787',66200,TO_DATE('44072', 'J'));
INSERT INTO EMP VALUES('EMP49','Carly Mcknight','DEPT4','DESG4','F','845-765 Lectus St.','Kazanlk','Kerala','590611',39000,TO_DATE('44034', 'J'));
INSERT INTO EMP VALUES('EMP50','Zahir Mcfarland','DEPT1','DESG0','M','P.O. Box 577, 8698 Arcu Av.','Sofia','BR','382093',69900,TO_DATE('43922', 'J'));
INSERT INTO EMP VALUES('EMP51','Veda Wise','DEPT4','DESG1','M','Ap #731-3770 Luctus. Street','Panagyurishte','Punjab','749892',43300,TO_DATE('43863', 'J'));
INSERT INTO EMP VALUES('EMP52','Zoe Austin','DEPT1','DESG0','M','P.O. Box 769, 7298 Feugiat. Av.','Burgas','Uttar Pradesh','662055',55600,TO_DATE('44030', 'J'));
INSERT INTO EMP VALUES('EMP53','Anjolie Ramirez','DEPT0','DESG2','M','Ap #161-3536 Dis Street','Blagoevgrad','CT','332662',53500,TO_DATE('43863', 'J'));
INSERT INTO EMP VALUES('EMP54','Jolene Hensley','DEPT3','DESG2','F','7019 Dui, Rd.','Kyustendil','JK','898336',30200,TO_DATE('43993', 'J'));
INSERT INTO EMP VALUES('EMP55','Zelda Shannon','DEPT3','DESG0','F','3636 Et St.','Peshtera','Gujarat','648659',33900,TO_DATE('44024', 'J'));
INSERT INTO EMP VALUES('EMP56','Samantha Woods','DEPT1','DESG3','M','Ap #670-720 Proin Road','Lom','UP','779241',54500,TO_DATE('44047', 'J'));
INSERT INTO EMP VALUES('EMP57','Yuli Dotson','DEPT3','DESG2','M','617-1867 Vel Ave','Stara Zagora','Maharastra','666782',41000,TO_DATE('43929', 'J'));
INSERT INTO EMP VALUES('EMP58','Britanni Wade','DEPT3','DESG0','M','9709 Tortor, Rd.','Stara Zagora','KA','474833',32800,TO_DATE('43892', 'J'));
INSERT INTO EMP VALUES('EMP59','Brianna Mcgowan','DEPT2','DESG1','F','801 Luctus Av.','Kharmanli','Rajasthan','467906',73400,TO_DATE('43988', 'J'));
INSERT INTO EMP VALUES('EMP60','Irma Wells','DEPT4','DESG2','M','7998 Donec Avenue','Peshtera','Maharastra','716729',50600,TO_DATE('44082', 'J'));
INSERT INTO EMP VALUES('EMP61','Leilani Reilly','DEPT1','DESG0','F','211-2589 Non, Street','Chirpan','WB','725884',56900,TO_DATE('44076', 'J'));
INSERT INTO EMP VALUES('EMP62','Nina Holloway','DEPT0','DESG0','F','Ap #518-4805 Dolor. Ave','Gotse Delchev','UP','868521',52300,TO_DATE('43951', 'J'));
INSERT INTO EMP VALUES('EMP63','Addison Hernandez','DEPT1','DESG2','M','Ap #270-4233 Eleifend Rd.','Gotse Delchev','Karnataka','995218',45900,TO_DATE('43893', 'J'));
INSERT INTO EMP VALUES('EMP64','Knox Hill','DEPT3','DESG2','F','1002 Tristique Rd.','Nova Zagora','Assam','741713',57500,TO_DATE('44030', 'J'));
INSERT INTO EMP VALUES('EMP65','Hyatt Good','DEPT1','DESG2','M','5348 In Rd.','Gabrovo','KA','531809',35200,TO_DATE('43856', 'J'));
INSERT INTO EMP VALUES('EMP66','Gregory Serrano','DEPT0','DESG0','F','235-1562 Eleifend St.','Berkovitsa','Uttar Pradesh','640439',48600,TO_DATE('43988', 'J'));
INSERT INTO EMP VALUES('EMP67','Henry Wilkins','DEPT2','DESG0','M','Ap #628-8055 Odio Av.','Nova Zagora','GJ','258932',72700,TO_DATE('44090', 'J'));
INSERT INTO EMP VALUES('EMP68','Clark Diaz','DEPT4','DESG2','M','892-7846 Est, Rd.','Rakovski','UP','101562',73900,TO_DATE('44024', 'J'));
INSERT INTO EMP VALUES('EMP69','Ferris Hernandez','DEPT1','DESG2','M','P.O. Box 571, 9278 Risus. St.','Kazanlk','UP','207702',71100,TO_DATE('44084', 'J'));
INSERT INTO EMP VALUES('EMP70','Branden Good','DEPT0','DESG0','F','762-4816 Faucibus Road','Kardzhali','TN','171388',45400,TO_DATE('43969', 'J'));
INSERT INTO EMP VALUES('EMP71','Hope Grimes','DEPT1','DESG2','M','405-6902 Non St.','Lovech','Odisha','565343',68600,TO_DATE('43857', 'J'));
INSERT INTO EMP VALUES('EMP72','Griffith Langley','DEPT1','DESG3','M','Ap #112-624 Commodo Street','Gotse Delchev','Tamil Nadu','751581',32100,TO_DATE('43872', 'J'));
INSERT INTO EMP VALUES('EMP73','Ulla Franco','DEPT0','DESG0','F','Ap #847-8844 Purus. Rd.','Karnobat','HR','373285',29200,TO_DATE('43902', 'J'));
INSERT INTO EMP VALUES('EMP74','Jael Parsons','DEPT4','DESG1','M','716-9146 Ultrices Street','Sofia','Kerala','299113',66200,TO_DATE('44007', 'J'));
INSERT INTO EMP VALUES('EMP75','Tobias Prince','DEPT1','DESG4','F','572-3824 Integer Ave','Gorna Oryakhovitsa','UP','617492',66800,TO_DATE('44020', 'J'));
INSERT INTO EMP VALUES('EMP76','Colleen Long','DEPT4','DESG4','F','116-4554 Parturient Ave','Haskovo','Bihar','720494',63200,TO_DATE('43963', 'J'));
INSERT INTO EMP VALUES('EMP77','Micah Evans','DEPT4','DESG1','M','835-3986 Enim St.','Pleven','Kerala','844364',39300,TO_DATE('44002', 'J'));
INSERT INTO EMP VALUES('EMP78','Odessa Key','DEPT3','DESG3','F','P.O. Box 686, 784 Nisl. Ave','Dimitrovgrad','Andhra Pradesh','848290',44400,TO_DATE('43887', 'J'));
INSERT INTO EMP VALUES('EMP79','Galena Flowers','DEPT0','DESG0','F','Ap #933-6077 Nam Av.','Kharmanli','West Bengal','287315',36800,TO_DATE('43948', 'J'));
INSERT INTO EMP VALUES('EMP80','Yuli Ballard','DEPT0','DESG2','F','P.O. Box 879, 7118 Elementum, Street','Dupnitsa','West Bengal','512098',59400,TO_DATE('43970', 'J'));
INSERT INTO EMP VALUES('EMP81','Kessie Norris','DEPT0','DESG0','F','652-9224 Molestie St.','Pleven','Bihar','172972',69300,TO_DATE('43860', 'J'));
INSERT INTO EMP VALUES('EMP82','Francis Alvarez','DEPT0','DESG0','F','P.O. Box 758, 1779 Ultrices Street','Cherven Bryag','AP','415025',53500,TO_DATE('43923', 'J'));
INSERT INTO EMP VALUES('EMP83','Jelani Vaughan','DEPT0','DESG2','F','7899 Nisi Avenue','Gorna Oryakhovitsa','UP','174354',72800,TO_DATE('43861', 'J'));
INSERT INTO EMP VALUES('EMP84','Lyle Odonnell','DEPT4','DESG1','M','Ap #406-6684 Vulputate, Avenue','Sliven','WB','922090',30600,TO_DATE('43991', 'J'));
INSERT INTO EMP VALUES('EMP85','Abra Strong','DEPT0','DESG3','M','Ap #766-5805 Nisi Av.','Plovdiv','Kerala','741870',51400,TO_DATE('44068', 'J'));
INSERT INTO EMP VALUES('EMP86','Adrienne Massey','DEPT4','DESG4','M','9194 Amet Ave','Kardzhali','Delhi','172037',69800,TO_DATE('43923', 'J'));
INSERT INTO EMP VALUES('EMP87','Haviva Daniels','DEPT4','DESG4','M','P.O. Box 258, 3541 Risus Av.','Karnobat','MP','430344',29700,TO_DATE('44020', 'J'));
INSERT INTO EMP VALUES('EMP88','Brielle Mckee','DEPT0','DESG1','M','348-9791 Nibh Road','Karnobat','Bihar','864262',28400,TO_DATE('43912', 'J'));
INSERT INTO EMP VALUES('EMP89','Brett Herrera','DEPT0','DESG4','M','P.O. Box 896, 372 Massa Rd.','Pernik','MH','572692',66700,TO_DATE('44042', 'J'));
INSERT INTO EMP VALUES('EMP90','Sierra Villarreal','DEPT3','DESG1','M','P.O. Box 234, 6418 Natoque Rd.','Kazanlk','Andhra Pradesh','150269',35000,TO_DATE('43967', 'J'));
INSERT INTO EMP VALUES('EMP91','Richard Haynes','DEPT0','DESG2','F','849-4743 Sagittis. Road','Shumen','PB','629698',40800,TO_DATE('44020', 'J'));
INSERT INTO EMP VALUES('EMP92','Macon Elliott','DEPT3','DESG1','F','Ap #610-3146 Vivamus Av.','Silistra','Tamil Nadu','208377',58800,TO_DATE('44036', 'J'));
INSERT INTO EMP VALUES('EMP93','Melanie Davidson','DEPT2','DESG1','F','6465 Nibh Ave','Svilengrad','MP','930903',38200,TO_DATE('44028', 'J'));
INSERT INTO EMP VALUES('EMP94','Jada Farley','DEPT3','DESG2','M','Ap #951-4625 Justo. Road','Smolyan','WB','278533',29000,TO_DATE('43834', 'J'));
```
```sql
INSERT INTO EMP (EMP_CODE, EMP_NAME, DESIG_CODE, SEX, ADDRESS, CITY, STATE, PIN, JN_DT) VALUES('EMP95','Sutanu Mondol', 'DESG0', 'M','Ikhane thake','KOLKATA','WEST BENGAL','700XXX',TO_DATE('12/01/2001', 'DD/MM/YYYY'));
INSERT INTO EMP (EMP_CODE, EMP_NAME, DESIG_CODE, SEX, ADDRESS, CITY, STATE, PIN, JN_DT) VALUES('EMP96','Shashi', 'DESG1', 'M','Rastae thake','KOLKATA','WEST BENGAL','700YYY',TO_DATE('10/02/2009', 'DD/MM/YYYY'));
INSERT INTO EMP (EMP_CODE, EMP_NAME, DESIG_CODE, SEX, ADDRESS, CITY, STATE, PIN, JN_DT) VALUES('EMP97','Akash', 'DESG1', 'M','Oikhane thake','KOLKATA','WEST BENGAL','700ZZ',TO_DATE('01/10/2010', 'DD/MM/YYYY'));
```
```sql
SELECT NAME, DESC_DESCRIP FROM EMP, DESCRIPTION
```