
select count(*) from categories;
select count(*) from customers;
select count(*) from employees;
select count(*) from orderdetails;
select count(*) from orders;
select count(*) from products;
select count(*) from shippers;
select count(*) from suppliers;


 select categoryName from categories;
 select country from customers;
 select city, country from customers;
 select CustomerName  from customers where city='Madrid' ;
 select CustomerID from customers where country='Germany';
 
 select CustomerID, CustomerName from customers where country='Germany' or 'Spain';
 
 select *from customers where city='London' and country='UK';
 select *from customers where city like 'b%';
 select *from customers where country not in ('Canada' ,'Belgium');
 
 select *from customers where country in ('Canada','France' ,'Germany','Italy' ,'Japan','UK','US');
 
 select *from customers where PostalCode like '%31%';
 
 select *from customers where PostalCode like '%00%' and city=('Rome' or 'Paris');
 
 select *from customers where country not in ('Salzburg');
 
 select *from employees where BirthDate like '%-07-%';
 
 select *from employees where Notes like '%BA%';
 
select *from suppliers where country in ('USA','Japan');

select distinct(country),count(*) as supplier_count from suppliers group by country;

select distinct(city),count(*) as name_count  from customers group by city; 

select distinct(employeeID),count(*) as order_count from orders group by employeeID;

select distinct(customerID), count(*) as order_count from customers group by customerID; 

select *from orders where shipperID in ('1','3');

select *from  products where categoryID='1';
select *from products where ProductName like 'b%';
