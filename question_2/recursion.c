#include <stdio.h>

// Recursive function to calculate F(n)
int recursiveFib(int n) {
    // Base cases
    if (n == 0) return 0; // F(0) is 0
    if (n == 1) return 1; // F(1) is 1
    if (n == 2) return 2; // F(2) is 2

    // Recursive calculation of F(n) using the recurrence relation
    return recursiveFib(n - 3) + recursiveFib(n - 2); // F(n) = F(n - 3) + F(n - 2)
}

int main() {
    int n = 5; // Example value for n, change as needed
    
    // Calculate and print F(n) using the recursive function
    printf("F(%d) = %d\n", n, recursiveFib(n));

    return 0;
}
