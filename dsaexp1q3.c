#include <stdio.h>

void convertCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str); 

    printf("Original string: %s\n", str);

    convertCase(str);

    printf("String after case conversion: %s\n", str);

    return 0;
}