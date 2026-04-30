// Recursive Fibonacci
#include <stdio.h>

int fib(int n) {
    // Base cases
    if (n <= 1) return n;
    
    // Recursive case
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;

    printf("Enter the value of n:\n");
    scanf("%d", &n);

    printf("Fibonacci number at position %d is: %d\n", n, fib(n));
    return 0;
}
