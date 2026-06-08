# E-commerce Order Processing — OOP Refactoring and UML Modeling

## Overview

This repository contains a laboratory work focused on Object-Oriented Design and code refactoring.

The project models a simplified e-commerce order processing system. It was refactored from a monolithic "God Object" architecture into a highly modular, maintainable design utilizing object-oriented principles, design patterns, modular testing, and UML modeling.

## Code Documentation

The project includes complete code documentation generated using Doxygen. 
The documentation covers all classes, interfaces, and methods, and is hosted via GitHub Pages:

https://karqyuu.github.io/ecommerce_system_refactoring/

## Main Refactoring Changes

The following architectural and structural changes were implemented:

- The "God Object" anti-pattern was eliminated from the `order_processor` class.
- The Single Responsibility Principle (SRP) was strictly enforced by extracting calculation and payment logic into separate components.
- The Strategy design pattern was implemented for dynamic discount calculations (`discount_strategy` interface with `vip_discount`, `student_discount`, and `regular_discount` implementations).
- The Strategy design pattern was implemented for payment processing (`payment_strategy` interface with `credit_card_payment`, `paypal_payment`, and `cash_payment` implementations).
- Dependency Injection (DI) was utilized to pass strategy objects into the `order_processor`, completely removing hardcoded `if-else` business logic.
- A monolithic test file was split into a custom modular testing suite.
- Doxygen comments were added to all header files.
- UML diagrams representing the system "Before" and "After" the refactoring were generated.

## Project Structure

```text
.
├── diagrams_after/          # PlantUML diagrams for the refactored architecture
├── diagrams_before/         # PlantUML diagrams for the initial monolithic code
├── docs/                    # Doxygen generated HTML documentation
├── include/
│   ├── discount_strategy.h  # Discount strategy interfaces and classes
│   ├── item.h               # Core domain entity
│   ├── order_processor.h    # Main orchestrator class
│   └── payment_strategy.h   # Payment strategy interfaces and classes
├── src/
│   ├── main.cpp             # Application entry point
│   └── order_processor.cpp  # Order processor implementation
├── tests/
│   ├── test_errors.cpp      # Exception and error handling tests
│   ├── test_main.cpp        # Test suite runner
│   ├── test_regular.cpp     # Standard customer logic tests
│   ├── test_registry.h      # Test declarations
│   ├── test_student.cpp     # Student logic tests
│   └── test_vip.cpp         # VIP logic tests
├── Doxyfile                 # Doxygen configuration
├── glossary.md              # Domain terminology
└── README.md                # Project documentation
```

## UML Diagrams

PlantUML source files and exported images are categorized into two directories: `diagrams_before` and `diagrams_after`. 

The project contains the following UML diagram types to illustrate the architectural shift:

| Diagram Type | Purpose |
|---|---|
| Use Case | Shows actor interactions with the e-commerce system. |
| Class | Illustrates the transition from a monolithic class to a Strategy pattern hierarchy using interfaces. |
| Activity | Demonstrates the simplified algorithm flow achieved by replacing nested `if-else` conditions with polymorphism. |
| Sequence | Maps the sequential object collaboration and delegation during the checkout process. |

## Build and Run

The project is written in standard C++ and does not require complex build systems. It can be compiled directly using `g++`.

### Main Application
To compile and run the main store simulation:

1. Open a terminal in the root directory of the project.
2. Compile the source files:
   ```bash
   g++ src/main.cpp src/order_processor.cpp -o my_shop
   ```
3. Run the application:
   ```bash
   ./my_shop
   ```

### Modular Unit Tests
The project features a custom modular testing framework to ensure the integrity of the refactored logic.

1. Compile the test suite:
   ```bash
   g++ tests/*.cpp src/order_processor.cpp -o run_tests
   ```
2. Run the tests:
   ```bash
   ./run_tests
   ```

## Refactoring Summary

The original project functioned correctly but suffered from severe design limitations:
- The core logic was heavily coupled within a single monolithic file.
- Adding a new discount rule or payment method required modifying the core algorithm, violating the Open-Closed Principle (OCP).
- Testing specific edge cases was difficult due to tangled dependencies.

The refactored version provides:
- High modularity and clear separation of concerns.
- Extensibility: New strategies can be added by creating a new class without touching existing code.
- Testability: Components can be instantiated and tested in isolation.
- Professional documentation and visual architecture blueprints.

## Technologies Used

- C++
- g++ Compiler
- PlantUML
- Doxygen