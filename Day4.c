// Reverse an Array In-Place
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
    
    // Two-pointer reversal
    int left = 0, right = n - 1;
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
    
    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}
