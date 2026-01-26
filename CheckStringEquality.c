#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int i = 0;
    int isEqual = 1; // Assuming that strings are equal

    // Reading two strings
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    // Comparing characters
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            isEqual = 0;
            break;
        }
        i++;
    }

    // Printing the result
    if (isEqual) {
        printf("Strings are equal");
    } else {
        printf("Strings are not equal");
    }

    return 0;
}
