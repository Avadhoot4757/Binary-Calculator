BC Utility - Binary Calculator for Linux
Overview
BC Utility is a binary calculator implemented in C for Linux. It performs arithmetic operations on expressions involving very large numbers, adhering to the BODMAS rule. The calculator supports addition, subtraction, multiplication, and division. By using a doubly linked list, it handles numbers that exceed the storage capacity of any primitive data type. The utility also allows users to specify the desired precision for the result, calculating up to the specified decimal points.

Features
Supports large numbers: Handles arithmetic operations on numbers that cannot be stored in standard primitive data types.
BODMAS rule: Correctly evaluates arithmetic expressions according to the BODMAS (Brackets, Orders, Division/Multiplication, Addition/Subtraction) rule.
Precision: Users can specify the precision of the result, calculating up to the specified number of decimal points.
Operations: Supports addition, subtraction, multiplication, and division.
Data Structures
Doubly Linked List
Used to store and manage large numbers.
Provides efficient insertion and deletion operations.
Stack
Used to manage operators and operands during the evaluation of expressions.
Facilitates the implementation of the BODMAS rule.
