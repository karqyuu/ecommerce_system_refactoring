# Glossary: E-commerce Order Processing (Post-Refactoring)

## 1. Purpose of the Glossary

This glossary describes the terms used in the refactored version of the e-commerce order processing project. The project demonstrates the transition from a monolithic architecture ("God Object") to a modular, flexible design using object-oriented principles and design patterns.

## 2. Domain Terms

### Item
A basic unit of product available in the store. It contains data about its name, unit price, and ordered quantity.

### Cart
A collection of selected `item` objects that the customer intends to purchase.

### Total Amount
The intermediate sum of all items in the cart before any discounts are applied.

### Discount
The amount deducted from the total amount. In the refactored system, this is no longer hardcoded but calculated dynamically via a specific `discount_strategy`.

### Final Amount
The final cost of the order after the discount is subtracted, which is passed to the injected `payment_strategy` for processing.

## 3. Software Design Terms

### Order Processor
The central coordinator class. Unlike the initial version, the refactored `order_processor` no longer contains the business logic for math calculations or payment gateways. Instead, it strictly delegates these tasks to external strategy objects.

### Strategy Pattern
A behavioral design pattern that allows defining a family of algorithms, putting each of them into a separate class, and making their objects interchangeable. Used in this project to handle various discount rules and payment methods without modifying the core processor.

### Discount Strategy
An interface (`discount_strategy`) defining the common contract for calculating discounts. Concrete implementations include `vip_discount`, `student_discount`, and `regular_discount`.

### Payment Strategy
An interface (`payment_strategy`) defining the common contract for processing payments. Concrete implementations include `credit_card_payment`, `paypal_payment`, and `cash_payment`.

### Single Responsibility Principle (SRP)
The "S" in SOLID principles, stating that a class should have only one reason to change. The refactored code heavily relies on SRP by separating order coordination, discount calculation, and payment processing into highly specialized, isolated classes.

### Dependency Injection
A programming technique where an object receives other objects that it depends on. In this project, the `order_processor` receives pointers to `discount_strategy` and `payment_strategy` through its `process_order` method parameters, rather than creating them internally.

### Interface
An abstract class (implemented using pure virtual functions in C++) that defines a set of methods a concrete class must implement. `discount_strategy` and `payment_strategy` act as interfaces.

### Unit Test
An automated test that checks an isolated part of the program. The modular test suite verifies each strategy and the core processor independently.

## 4. UML Terms Used in This Project

### UML
UML, or Unified Modeling Language, is a visual modeling language used to describe software systems.

### Use Case Diagram
Describes how external users or actors interact with the system (e.g., placing an order, processing a payment).

### Class Diagram
Describes classes, attributes, methods, and relationships. The post-refactoring diagram highlights the use of interfaces and inheritance representing the Strategy pattern.

### Activity Diagram
Shows a workflow or algorithm as a sequence of actions. The updated diagram demonstrates a simplified, linear flow replacing the old complex `if-else` trees.

### Sequence Diagram
Shows interactions between objects over time, specifically illustrating how `order_processor` delegates tasks to `discount` and `payment` objects.

## 5. Abbreviations

| Abbreviation | Meaning                           |
| ------------ | --------------------------------- |
| UML          | Unified Modeling Language         |
| OOP          | Object-Oriented Programming       |
| SRP          | Single Responsibility Principle   |
| DI           | Dependency Injection              |
| UAH          | Ukrainian Hryvnia                 |