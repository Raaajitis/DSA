#include <stdio.h>
#include <string.h>

#define MAX 100

int isMatching(char opening, char closing) {

    if (opening == '(' && closing == ')')
        return 1;

    if (opening == '{' && closing == '}')
        return 1;

    if (opening == '[' && closing == ']')
        return 1;

    return 0;
}

int isBalanced(char expression[]) {

    char stack[MAX];

    int top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {

        char current = expression[i];

        // Opening bracket
        if (current == '(' ||
            current == '{' ||
            current == '[') {

            stack[++top] = current;
        }

        // Closing bracket
        else if (current == ')' ||
                 current == '}' ||
                 current == ']') {

            // Nothing available to match
            if (top == -1) {
                return 0;
            }

            // Incorrect type of bracket
            if (!isMatching(stack[top], current)) {
                return 0;
            }

            // Correct pair found
            top--;
        }
    }

    // Stack must be empty
    if (top == -1) {
        return 1;
    }

    return 0;
}

int main() {

    char expression[] = "{[(a+b) * (c-d)]}";

    if (isBalanced(expression)) {

        printf("Expression is balanced.\n");

    } else {

        printf("Expression is not balanced.\n");
    }

    return 0;
}