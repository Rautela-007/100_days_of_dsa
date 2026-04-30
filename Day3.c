//Linear Search with Comparison Count
#include <stdio.h>

int main() {
    int n, k, comparisons = 0;
    int arr[100];
    int found = -1;
    
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter %d array elements separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search:\n");
    scanf("%d", &k);
    
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            found = i;
            break;
        }
    }
    
    if (found != -1) {
        printf("Found at index %d\n", found);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);
    
    return 0;
}
