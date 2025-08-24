#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char str[]);

int main() {
    char str[100];
    char repeat;
    
    do {
        printf("Enter a string: ");
        fgets(str, sizeof(str), stdin);
        
        str[strcspn(str, "\n")] = 0;
        
        if (is_palindrome(str)) {
            printf("\"%s\" is a Palindrome!\n", str);
        } else {
            printf("\"%s\" is NOT a Palindrome!\n", str);
        }
        
        printf("\nDo you want to repeat the process? (Y/N): ");
        scanf(" %c", &repeat);
        while (getchar() != '\n'); // Clear input buffer
        
    } while (repeat == 'Y' || repeat == 'y');
    
    return 0;
}

int is_palindrome(char str[]) {
    int left = 0, right = strlen(str) - 1;
    
    while (left < right) {
        while (left < right && str[left] == ' ') left++;
        while (left < right && str[right] == ' ') right--;
        
        if (tolower(str[left]) != tolower(str[right])) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}