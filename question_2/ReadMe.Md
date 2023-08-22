# Polynomial Multiplication and Fibonacci Series Calculation - Code Overview

This README provides an overview of four different pieces of code, each with a brief explanation of what they do, along with their advantages and disadvantages.

## Code 1(iterative.c): Iterative Function

### Description

- It calculates F(n) numbers using an iterative approach using dynamic programming to store intermediate results.

### Advantages

- Efficient with linear time complexity (O(n)).
- No need for extra memory beyond the DP array.

### Disadvantages

- May require more code compared to the recursive method, especially for more complex problems.

## Code 2(memoization.c): Memoization-Based

### Description

- A memoization array (`memo`) is used to store computed values and calculates and prints the nth Fibonacci number.

### Advantages

- Avoids redundant calculations using memoization.
- Simpler code structure compared to the iterative approach.

### Disadvantages

- Still has some overhead due to function calls and memory usage for memoization array.

## Code 3(recursion.c): Recursive

### Description

- It recursively computes F(n) using a recurrence relation and calculates, then prints the nth number.

### Advantages

- Simple and straightforward implementation.
- Suitable for small values of n.

### Disadvantages

- Inefficient for large values of n due to redundant calculations.
- High time complexity for large n.

## Bonus Code

## Code 4(polnomial.c): Polynomial Multiplication

### Description

- It defines a structure to represent polynomials with three coefficients.
- The `mul` function multiplies two polynomials.
- The `polypow` function calculates a polynomial raised to a power.
- It calculates and prints specific terms in a polynomial series.

### Advantages

- Useful for various mathematical operations involving polynomials.
- Modular and reusable functions for polynomial manipulation.

### Disadvantages

- May not be as efficient as specialized polynomial libraries for very large polynomials.
- Limited to polynomials with three coefficients.

## Conclusion

Each piece of code serves a different purpose and has its own set of advantages and disadvantages. The choice of which code to use depends on the specific requirements of the task and the input data size.
