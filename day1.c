#include <stdio.h>

int main() {
    int n, pos, x;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    int arr[n + 1];

    printf("Enter %d array elements separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to insert at (1 to %d):\n", n + 1);
    scanf("%d", &pos);

    printf("Enter element to insert:\n");
    scanf("%d", &x);

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;

    printf("Updated array: ");
    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}
