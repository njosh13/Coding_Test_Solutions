#include <stdio.h>
#include <stdlib.h>

// Adding Enum Types 
typedef enum TypeTag {
    ADD,    // +
    SUB,    // -
    MUL,    // *
    FIBO,    // fibonacci
    LIT     // Literal (a numeric value)
} TypeTag;

// Definition of a Node structure for representing expressions
typedef struct Node {
    TypeTag type;        // Type of the node (e.g., ADD, SUB, LIT)
    int value;           // Value (only used for LIT nodes)
    struct Node *left;   // Left child of the node
    struct Node *right;  // Right child of the node
} Node;

#define MAXN 10 // maximum number of Fibonacci numbers stored in memory.
int fib[MAXN];

// Function to create a new node with the given type
Node* makeFunc(TypeTag type) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a LIT node with the given value
Node* makeValue(int value) {
    Node *newNode = makeFunc(LIT);
    newNode->value = value;
    return newNode;
}

// Function to calculate the nth Fibonacci number using dynamic programming
int fibonacci(int n) {
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n-1]; // Return the 'n'th Fibonacci number (0-indexed). Which will help attain the fibo = 2 output when F(4)

}

// Function to calculate the value of a node in the expression tree
int calc(Node* node) {
    if (node->type == ADD) {
        return calc(node->left) + calc(node->right);
    }
    else if (node->type == SUB) {
        return calc(node->left) - calc(node->right);
    }
    else if (node->type == MUL) {
        return calc(node->left) * calc(node->right);
    }
    else if (node->type == FIBO) {
        return fibonacci(calc(node->left));
    }
    else if (node->type == LIT) {
        return node->value;
    }
    printf("Invalid node type %d\n", node->type);
    exit(1);
}

int main() {
    // Initialize the fib array with -1
    for (int i = 0; i < MAXN; i++) {
        fib[i] = -1;
    }
    
    // Create a tree representing a mathematical expression
    Node *add = makeFunc(ADD);
    add->left = makeValue(10);
    add->right = makeValue(6);
    
    Node *mul = makeFunc(MUL);
    mul->left = makeValue(5);
    mul->right = makeValue(4);
    
    Node *sub = makeFunc(SUB);
    sub->left = makeValue(calc(add)); // Evaluate add node and use the result
    sub->right = makeValue(calc(mul)); // Evaluate mul node and use the result
    
    Node *fibo = makeFunc(FIBO);
    fibo->left = makeValue(abs(calc(sub))); // Evaluate sub node and use the absolute value which will be '4' in this case. 
    fibo->value = fibonacci(calc(fibo->left)); // Calculate Fibonacci of the result.


    // Calculate and print the values of different nodes in the expression tree
    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));

    // Deallocate the dynamically allocated memory
    free(add); 
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}




