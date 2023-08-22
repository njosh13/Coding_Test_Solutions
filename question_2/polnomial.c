#include <stdint.h>
#include <stdio.h>

// Define a structure to represent a polynomial with three coefficients
typedef struct poly_s {
    int64_t x0, x1, x2;
} poly_s;

// Function to multiply two polynomials 'a' and 'b'
poly_s mul(poly_s a, poly_s b) {
    // Perform polynomial multiplication and return the result
    return (poly_s){
        a.x0 * b.x0 + a.x2 * b.x1 + a.x1 * b.x2,        // x0 coefficient
        a.x1 * b.x0 + a.x0 * b.x1 + a.x2 * b.x2 +       // x1 coefficient
        a.x2 * b.x1 + a.x1 * b.x2,
        a.x2 * b.x0 + a.x1 * b.x1 + a.x0 * b.x2 +       // x2 coefficient
        a.x2 * b.x2
    };
}

// Function to calculate the polynomial 'x' raised to the power of 'n'
poly_s polypow(poly_s x, int n) {
    poly_s r = {1, 0, 0}; // Initialize result as (1, 0, 0)
    while (n) {
        if (n & 1)  // If 'n' is odd, multiply the result by 'x'
            r = mul(r, x);
        x = mul(x, x); // Square 'x'
        n >>= 1; // Halve 'n'
    }
    return r;
}

int main() {
    for (int i = 0; i <= 50; i++) {
        // Calculate the value of a specific term in the polynomial series
        int64_t term = mul((poly_s){0, 2, 1}, polypow((poly_s){0, 1, 0}, i)).x0;
        printf("%d: %ld\n", i, term);
    }
    return 0;
}
