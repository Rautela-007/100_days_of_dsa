// Find Maximum and Minimum Element
#include <stdio.h>

int main() {
    int n;
    int arr[100];
    
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter %d array elements separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int max = arr[0];
    int min = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    
    return 0;
}
