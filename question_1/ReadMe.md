# Expression Evaluation with Fibonacci

This code demonstrates how to evaluate a mathematical expression using a tree-like structure. It also includes the calculation of Fibonacci numbers using dynamic programming. This README provides an explanation of how I went about to solve it.

## Code Overview

The code includes the following key components:

### Enum Definition (enum TypeTag)

We start by defining an enumeration called `TypeTag`. This enumeration represents different types of operations in the expression tree, including addition (`ADD`), subtraction (`SUB`), multiplication (`MUL`), and Fibonacci (`FIBO`).

### Node Structure (struct Node)

The `Node` structure is defined to hold information about a node in the computation process. It includes two members:

- `enum TypeTag type`: This member indicates the type of operation the node represents.
- `int value`: This member stores the computed value associated with the node, which is used for literal nodes (`LIT`).

### Maximum Number Definition (define MAXN 10)

We set the maximum number of Fibonacci numbers to be stored in memory to 10. This ensures proper memory management.

### Creating a Literal Node (makeValue)

The `makeValue` function creates a special node in our program to represent a numeric value. It takes a number as input and creates a node for that number, allowing us to use it in expressions.

### Fibonacci Function (fibonacci)

The `fibonacci` function calculates Fibonacci numbers using dynamic programming. It starts by initializing an array to store Fibonacci values and then iteratively computes the sequence. The function returns the (n-1)-th Fibonacci number (0-indexed), which is used for the `FIBO` nodes in expressions.

### Calculation Function (calc)

The `calc` function takes a `Node*` as input and checks its type. Based on the type, it performs different calculations:

- For `ADD`, it adds the values of the left and right child nodes.
- For `SUB`, it subtracts the right child node's value from the left child node's value.
- For `MUL`, it multiplies the values of the left and right child nodes.
- For `FIBO`, it calculates the Fibonacci number of the (n-1)-th Fibonacci value, where n is the result of evaluating the left child node.
- For `LIT`, it simply returns the node's value, which represents a literal number.

## Usage

In the `main` function, you can see an example of how to create an expression tree and evaluate it. The code initializes the `fib` array, creates expression nodes, and calculates and prints the values of different nodes in the expression tree.

## Memory Management

The code includes memory management to free the dynamically allocated memory for each `Node` structure at the end of the program. This ensures that there are no memory leaks.

## Thank You
