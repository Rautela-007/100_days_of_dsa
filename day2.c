#include <stdio.h>

// Define structure
struct Array {
    int arr[100];
    int size;
};

int main() {
    struct Array A;
    int pos;

    printf("Enter number of elements:\n");
    scanf("%d", &A.size);

    printf("Enter %d array elements separated by spaces:\n", A.size);
    for (int i = 0; i < A.size; i++) {
        scanf("%d", &A.arr[i]);
    }

    printf("Enter position to delete (1 to %d):\n", A.size);
    scanf("%d", &pos);

    // Validate position
    if (pos < 1 || pos > A.size) {
        printf("Invalid position");
        return 0;
    }

    // Shift elements to the left
    for (int i = pos - 1; i < A.size - 1; i++) {
        A.arr[i] = A.arr[i + 1];
    }

    // Decrease size
    A.size--;

    // Print updated array
    printf("Updated array after deletion: ");
    for (int i = 0; i < A.size; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", A.arr[i]);
    }
    printf("\n");

    return 0;
}
