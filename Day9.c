// Mirror the Code Name
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];

    printf("Enter the code name/string to reverse:\n");
    scanf("%s", str);
    
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
    
    printf("Reversed string: %s\n", str);
    return 0;
}
