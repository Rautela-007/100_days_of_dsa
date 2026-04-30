// Compute Power Using Recursion
#include <stdio.h>

int power(int a, int b) {
    // Base case
    if (b == 0) return 1;
    
    // Recursive case
    return a * power(a, b - 1);
}

int main() {
    int a, b;

    printf("Enter base number:\n");
    scanf("%d", &a);

    printf("Enter exponent:\n");
    scanf("%d", &b);

    printf("%d raised to the power %d is: %d\n", a, b, power(a, b));
    return 0;
}
