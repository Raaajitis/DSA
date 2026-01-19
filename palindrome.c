#include <stdio.h>

int main() {
    char str[100];
    
    // Reading string
    scanf("%s", str);

    int start = 0;
    int end = 0;

    // Finding length of string manually
    while (str[end] != '\0') {
        end++;
    }
    end--; // Moving to last character

    // Checking palindrome
    while (start < end) {
        if (str[start] != str[end]) {
            printf("Not Palindrome");
            return 0;
        }
        start++;
        end--;
    }

    // If no mismatches are found
    printf("This is a Palindrome");

    return 0;
}
