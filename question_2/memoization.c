#include <stdio.h>

int memo[1000]; // Array to store computed Fibonacci values

// Function to calculate F(n) using memoization (dynamic programming)
int memoFib(int n) {
    // Base cases
    if (n == 0) return 0; // F(0) is 0
    if (n == 1) return 1; // F(1) is 1
    if (n == 2) return 2; // F(2) is 2

    // If F(n) has already been computed, return the stored value
    if (memo[n] != -1) return memo[n];

    // Calculate F(n) using memoization and store the result
    memo[n] = memoFib(n - 3) + memoFib(n - 2); // F(n) = F(n - 3) + F(n - 2)

    return memo[n]; // Return the computed Fibonacci value for F(n)
}

int main() {
    int n = 50; // Value of n to calculate F(n)
    
    // Initialize the memoization array with -1 values
    for (int i = 0; i < 1000; i++) memo[i] = -1;

    // Calculate and print F(n) using memoization
    printf("F(%d) = %d\n", n, memoFib(n));

    return 0;
}
