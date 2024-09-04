# younixShop

### Brief Description

**younixShop** is a C++ program. It is an attempt to simulate an inventory management software using only C++ code. At its core, **younixShop** primarily uses C++ file handling operations to carry out all types of transactions.

> This project was tested and deployed orginally on `TurboC++`. In the upcoming time, I will make it platform-independent.

### Detailed Description of the Functionality

This program provides the Admin to check and handle the database of products using various operations. These operations include the addition, deletion and modification of records of products available. The records of the products include the product's unique system generated product ID, its name, category, price per piece and quantity available.

The program also provides the admin the access to the customer database – customer’s unique system generated ID, name, mobile number, address, and password. The provision of viewing a customer’s password has been provided to the admin so as to let him serve as the person to which the customer will contact in case, he forgets the password. Keeping a record of the customer details allows the customer to enter their ID and password, and login without having to enter their details again in case of a revisit.

The customers can register themselves from a dedicated Customer Account Management System or, customers can create an account at the time of buying a product. The Younix Account of Customers allows them to track their bills with the Younix Store and store their details for future reference. Inside the customer account management system, they can Sign Up, if they are new to the site or can Login to make modifications to their account. The system gives the customer a unique system generated Customer ID and a 4-Digit numeric password, which the customer can change later by logging in to the dedicated customer account management system. The customer can review his full account details, modify their name, phone number, address, password and even view his previous bills of the purchases he made on the site. This password system introduces the concept of confidentiality and restricted access in the program.
Also, a dedicated Report Generation System has been created which provides a full-fledged report to the admin to monitor the company’s day-wise, month- wise, or year-wise progress. The reports include detailed information like the Total Revenue generated, Total Products sold, Individual Product Quantity sold and Individual Product Revenue generated. The Individual Product Quantity sold and Individual Product Revenue generated information allows the admin to track the sales of a particular product.

A dedicated Bill Management System has also been created which allows the admin to view all the bills or, to view a particular bill. The bills have a unique system generated ID. The bills give information including the customer ID, date of purchase, ID and Name of product purchased, price per product, quantity purchased and the total cost.

Also, a dedicated Customer Help Center has been also included where the customers can go if they face any problem accessing their account, a problem with their passwords or any other problem.

Dedicated menus are present in the main menu which provides specific access to admin interface, customer interface and products interface making the program more efficient and time saving.

### Descitption of Code Snippets

1. Classes Used

+---+
|   |
+---+