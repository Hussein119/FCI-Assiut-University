create database section ; 
use section ; 
create table doctor (
did varchar (14) primary key , docname varchar (20) not null default 'default'
 );
 create table course (
 C_code varchar (10), 
 C_name varchar (50) not null default 'Unknown',
 C_hour int not null default 3,
 Doctor_id varchar (14),
 primary key ( C_code ) , 
 foreign key (Doctor_id) references doctor (did)
 on delete set null on update cascade 
);
drop table course ;  
describe doctor ; 
describe course ; 
show tables ; 
insert into  doctor values ( '100' , 'ibrahem' )  ;
insert into  doctor values ( '300' , 'Ahmed Hosny' ) ;
insert into  doctor values ( '200' , 'mostafa' ) ;
select * from doctor ;
select  did , docname  from doctor ;
update doctor set docname = 'Mostafa Kamel' where did = '200';
update doctor set docname = 'Ibrahem El saman ' where did = '100';
delete from doctor where did = '200'; 
insert into course ( C_code , C_name , C_hour , Doctor_id ) values ('IS203','Systems analysis',3,'200');
select * from course ;
delete from doctor where did = '200' ; 
