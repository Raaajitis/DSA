#include <stdio.h>
#include <string.h>

#define MAX 1000

void removeAdjacentDuplicates(char str[]) {

    char stack[MAX];

    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {

        // Duplicate pair found
        if (top >= 0 &&
            stack[top] == str[i]) {

            top--;
        }

        // Different character
        else {

            stack[++top] = str[i];
        }
    }

    if (top == -1) {

        printf("Final string is empty.\n");
        return;
    }

    printf("Final string: ");

    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }

    printf("\n");
}

int main() {

    char str[] = "abbaca";

    removeAdjacentDuplicates(str);

    return 0;
}