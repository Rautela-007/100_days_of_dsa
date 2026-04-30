// Check Palindrome
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char str[1000];

    printf("Enter a string to check palindrome:\n");
    scanf("%s", str);
    
    int left = 0;
    int right = strlen(str) - 1;
    bool isPalindrome = true;
    
    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }
    
    printf("Palindrome: %s\n", isPalindrome ? "YES" : "NO");
    return 0;
}
