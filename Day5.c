// Arrange Arrival Logs
#include <stdio.h>

int main() {
    int n1, n2;
    int arr1[100], arr2[100], result[200];
    
    printf("Enter number of elements in first sorted array:\n");
    scanf("%d", &n1);

    printf("Enter %d elements of first sorted array separated by spaces:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    
    printf("Enter number of elements in second sorted array:\n");
    scanf("%d", &n2);

    printf("Enter %d elements of second sorted array separated by spaces:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    
    while (i < n1) result[k++] = arr1[i++];
    while (j < n2) result[k++] = arr2[j++];
    
    printf("Merged array: ");
    for (int i = 0; i < k; i++) {
        printf("%d", result[i]);
        if (i < k - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}
