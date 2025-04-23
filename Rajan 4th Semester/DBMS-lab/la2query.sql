create database rajandbms2;

use rajandbms2
create table student (
    id int,
    name varchar(100),
    gender varchar(10),
    program varchar(100),
    contact_number varchar(15),
    address varchar(150)
);
create table teacher (
    id int,
    name varchar(100),
    subject varchar(100),
    contact_number varchar(15),
    address varchar(150)
);




alter table student modify id int not null;
alter table teacher modify id int not null;

alter table student modify id int unique;
alter table teacher modify id int unique;

alter table teacher modify contact_number varchar(15) not null;

alter table student modify address varchar(150) not null;

alter table teacher add primary key (id);

alter table student add primary key (id);

alter table student alter column program set default 'CSIT';

alter table student alter column address set default 'Ekantakuna';

alter table teacher drop primary key;


alter table teacher modify id int NULL;

alter table student drop not null;


















