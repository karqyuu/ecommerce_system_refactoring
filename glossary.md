# Glossary: E-commerce Order Processing (Pre-Refactoring)

## 1. Purpose of the Glossary

This glossary describes the main terms used in the initial, pre-refactoring version of the e-commerce order processing project. 

The project models a simplified digital storefront where items are collected in a cart, discounts are calculated based on customer status, and payments are processed.

## 2. Domain Terms

### Item
An `item` is a basic unit of product available in the store. It contains data about its name, unit price, and available/ordered quantity.

### Cart
A cart is a collection of selected `item` objects that the customer intends to purchase.

### Order Processor
The `order_processor` is the central component of the initial system. It is a monolithic class that handles stock verification, price calculation, discount application, and payment processing all at once.

### Customer Type
A string parameter representing the category of the buyer, which determines the discount logic. In the initial code, possible values are `vip`, `student`, and `regular`.

### Payment Method
A string parameter defining how the customer pays for the order. In the initial code, possible values are `credit_card`, `paypal`, and `cash`.

### Total Amount
The intermediate sum of all items in the cart before any discounts are applied.

### Discount
The amount deducted from the total amount based on the customer type and volume of purchases.

### Final Amount
The final cost of the order after the discount is subtracted, which is then passed to the payment processing logic.

## 3. Software Design Terms

### Class
A class is a blueprint for creating objects. In this initial project, classes are used to model the `item` data structure and the `order_processor` logic.

### Object
An object is an instance of a class. 

### Encapsulation
Encapsulation is an object-oriented programming principle where internal data is hidden inside a class and accessed through public methods. In the initial code, encapsulation is weak because `item` properties are fully public and the processor directly manipulates them.

### God Object (Anti-Pattern)
A software design anti-pattern where a single class (in our case, `order_processor`) knows too much or does too much, violating the Single Responsibility Principle.

### Unit Test
A unit test is an automated test that checks a small part of the program, usually one class or function. 

## 4. UML Terms Used in This Project

### UML
UML, or Unified Modeling Language, is a visual modeling language used to describe software systems.

### Use Case Diagram
A Use Case diagram describes how external users or actors interact with the system. For this project, it shows actions like processing an order, checking stock, and paying.

### Class Diagram
A Class diagram describes classes, attributes, methods, and relationships between classes. Initially, this diagram highlights the overloaded nature of the `order_processor` class.

### Activity Diagram
An Activity diagram shows a workflow or algorithm as a sequence of actions and decisions. It is used here to illustrate the heavy `if-else` branching inside the original code.

### Sequence Diagram
A Sequence diagram shows interactions between objects over time. It describes the linear execution of the `process_order` method.

## 5. Abbreviations

| Abbreviation | Meaning                           |
| ------------ | --------------------------------- |
| UML          | Unified Modeling Language         |
| OOP          | Object-Oriented Programming       |
| SRP          | Single Responsibility Principle   |
| UAH          | Ukrainian Hryvnia                 |