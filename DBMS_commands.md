create table department(department_id number(3) constraint dept_pk PRIMARY KEY,dept_name varchar2(20) constraint dept_nn NOT NULL,manager_id number(3),location_id number(3))

create table employee2(emp_id number(3) primary key,first_name varchar2(20) NOT NULL,last_name varchar2(20) NOT NULL, salary number(8,2) check(salary>12000),
Phone_no number(10) check(length(Phone_no)=10),email varchar2(20) unique , department_id number(3), constraint emp_dep_id_fk foreign key(department_id) references department(department_id))

create table student as (select *from hr.departments)//copy structure with data
create table student2 as (select *from hr.departments where 1=2)//copy only structure
