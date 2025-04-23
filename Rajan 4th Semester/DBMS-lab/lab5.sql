create database rajan_northwinddml;
use rajan_northwinddml;
INSERT INTO categories (CategoryName, Description) 
VALUES 
('Electronics', 'Electronic devices and gadgets'),
('Books', 'All kinds of books');

SELECT * FROM  	rajan_northwinddml.categories;

INSERT INTO suppliers (SupplierName, ContactName, Address, City, PostalCode, Country, Phone) 
VALUES 
('Tech Supplies', 'Alice Johnson', '123 Tech Lane', 'Tech City', '12345', 'USA', '123-456-7890'),
('Book Distributors', 'Bob Smith', '456 Book Blvd', 'Book Town', '67890', 'USA', '098-765-4321'),
('Gadget World', 'Charlie Brown', '789 Gadget Rd', 'Gadget City', '54321', 'Canada', '456-123-7890');

SELECT * FROM rajan_northwinddml.suppliers;



INSERT INTO customers (CustomerName, ContactName, Address, City, PostalCode, Country) 
VALUES 
('John Doe', 'John', '123 Main St', 'New York', '10001', 'USA'),
('Jane Smith', 'Jane', '456 Elm St', 'Los Angeles', '90001', 'USA'),
('Michael Johnson', 'Michael', '789 Oak St', 'Chicago', '60601', 'USA'),
('Emily Davis', 'Emily', '101 Pine St', 'Houston', '77001', 'USA'),
('David Wilson', 'David', '202 Maple St', 'Phoenix', '85001', 'USA');

SELECT * FROM  rajan_northwinddml.customers;

INSERT INTO products (ProductName, SupplierID, CategoryID, Unit, Price) 
VALUES 
('Smartphone', 1, 1, 'Piece', 699),
('Laptop', 1, 1, 'Piece', 999),
('Fiction Book', 2, 2, 'Piece', 20),
('Non-fiction Book', 2, 2, 'Piece', 25);

SELECT * FROM rajan_northwinddml.products;

INSERT INTO employees (LastName, FirstName, BirthDate, Photo, Notes) 
VALUES 
('Anderson', 'Mark', '1980-05-15', 'mark.jpg', 'Notes about Mark'),
('Taylor', 'Laura', '1985-07-20', 'laura.jpg', 'Notes about Laura'),
('Brown', 'Chris', '1990-08-25', 'chris.jpg', 'Notes about Chris');

SELECT * FROM rajan_northwinddml.employees;

SET SQL_SAFE_UPDATES = 0;
UPDATE customers 
SET Country = "singapore"
WHERE Country = 'Brazil';
SET SQL_SAFE_UPDATES = 1; 

SELECT * FROM rajan_northwinddml.customers;
SET SQL_SAFE_UPDATES = 0;
UPDATE customers SET City = 'bangalore' WHERE City = 'Madrid City';
SET SQL_SAFE_UPDATES = 1; 
 
SELECT * FROM rajan_northwinddml.customers;

SET SQL_SAFE_UPDATES = 0;
UPDATE customers SET Country = 'Bhutanese' WHERE Country = 'German';
SET SQL_SAFE_UPDATES = 0;

SELECT * FROM rajan_northwinddml.customers;

SET SQL_SAFE_UPDATES = 0;
UPDATE customers SET Country = 'Thai' WHERE Country = 'Spanish';
SET SQL_SAFE_UPDATES = 1;
SELECT * FROM rajan_northwinddml.customers;

UPDATE customers SET City = 'Kathmandu', Country = 'Nepal' WHERE City = 'London';
SELECT * FROM rajan_northwinddml.customers; 

SET SQL_SAFE_UPDATES = 0;
UPDATE customers SET Country = 'SAARC Country' WHERE Country IN ('USA', 'Canada', 'UK', 'France', 'Germany', 'Italy', 'Japan');
SET SQL_SAFE_UPDATES = 1;
SELECT * FROM rajan_northwinddml.customers; 

SET SQL_SAFE_UPDATES = 0;
DELETE FROM orderdetails WHERE OrderID IN (SELECT OrderID FROM orders WHERE CustomerID IN (SELECT CustomerID FROM customers WHERE PostalCode LIKE '%31%'));
DELETE FROM orders WHERE CustomerID IN (SELECT CustomerID FROM customers WHERE PostalCode LIKE '%31%');
DELETE FROM customers 
WHERE PostalCode LIKE '%31%';
SET SQL_SAFE_UPDATES = 1;

SELECT * FROM rajan_northwinddml.customers; 

SET SQL_SAFE_UPDATES = 0;
DELETE FROM customers WHERE PostalCode LIKE '%00%' AND City IN ('Rome', 'Paris');
SET SQL_SAFE_UPDATES = 1;

SELECT * FROM rajan_northwinddml.customers; 

DELETE FROM customers 
WHERE PostalCode LIKE '%31%';

SELECT * FROM rajan_northwinddml.customers;
DELETE FROM orderdetails 
WHERE OrderID IN (SELECT OrderID FROM orders WHERE CustomerID IN 
(SELECT CustomerID FROM customers WHERE City != 'Salzburg'));
DELETE FROM orders 
WHERE CustomerID IN (SELECT CustomerID FROM customers WHERE City != 'Salzburg');
DELETE FROM customers 
WHERE City != 'Salzburg';

DELETE FROM employees WHERE MONTH(BirthDate) = 7;
SELECT * FROM rajan_northwinddml.employees;

DELETE FROM employees WHERE MONTH(BirthDate) = 8;
SELECT * FROM rajan_northwinddml.employees;

DELETE FROM orderdetails 
WHERE ProductID IN (SELECT ProductID FROM products WHERE SupplierID IN 
(SELECT SupplierID FROM suppliers WHERE Country IN ('Singapore', 'Japan')));

DELETE FROM products 
WHERE SupplierID IN (SELECT SupplierID FROM suppliers WHERE Country IN ('Singapore', 'Japan'));

DELETE FROM suppliers 
WHERE Country IN ('Singapore', 'Japan');

SELECT * FROM rajan_northwinddml.suppliers;

SELECT Country, COUNT(SupplierID) AS SupplierCount 
FROM suppliers GROUP BY Country;

SELECT City, COUNT(CustomerID) AS CustomerCount 
FROM customers  GROUP BY City;

SELECT EmployeeID, COUNT(OrderID) AS OrderCount 
FROM orders  GROUP BY EmployeeID;

