#include <stdio.h>

// Function to calculate F(n) using an iterative approach
int IterativeFunction(int n) {
    // Base cases
    if (n == 0) return 0;  // F(0) is 0
    if (n == 1) return 1;  // F(1) is 1
    if (n == 2) return 2;  // F(2) is 2
    
    // Initialize an array to store Fibonacci values
    int dp[n + 1];
    dp[0] = 0;  // Base case: F(0)
    dp[1] = 1;  // Base case: F(1)
    dp[2] = 2;  // Base case: F(2)
    
    // Calculate Fibonacci values for n >= 3
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 3] + dp[i - 2];  // F(n) = F(n - 3) + F(n - 2)
    }
    
    return dp[n];  // Return the calculated Fibonacci value for F(n)
}

int main() {
    int n = 10; // Value of n to calculate F(n)
    printf("F(%d) = %d\n", n, IterativeFunction(n));  // Print the result for F(10)
    return 0;
}
