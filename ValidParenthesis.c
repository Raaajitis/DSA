#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int isValid(char str[]) {

    for (int i = 0; i < strlen(str); i++) {

        char c = str[i];

        if (c == '(' || c == '{' || c == '[')
            push(c);

        else {

            if (isEmpty())
                return 0;

            char t = pop();

            if ((c == ')' && t != '(') ||
                (c == '}' && t != '{') ||
                (c == ']' && t != '['))
                return 0;
        }
    }

    return isEmpty();
}

int main() {

    char str[] = "{[()]}";

    if (isValid(str))
        printf("Valid Parentheses\n");
    else
        printf("Invalid Parentheses\n");

    return 0;
}