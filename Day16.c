// Frequency Counter in Array
#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int freq[1001] = {0}; // Assuming values 0-1000
    
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter %d array elements separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;
    }
    
    // Print in order of first appearance
    printf("Frequencies: ");
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] > 0) {
            printf("%d:%d ", arr[i], freq[arr[i]]);
            freq[arr[i]] = 0; // Mark as printed
        }
    }
    printf("\n");
    
    return 0;
}
