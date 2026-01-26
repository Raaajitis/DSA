#include <stdio.h>

int main() {
    char str[100];
    int start = 0, end = 0;
    char temp;

    // Reading string
    printf("Enter a string to reverse: ");
    scanf("%s", str);

    // Finding length of string
    while (str[end] != '\0') {
        end++;
    }
    end--; // Points to last character

    // Reversing string using two pointers
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    // Printing reversed string
    printf("Reversed string: %s", str);

    return 0;
}
