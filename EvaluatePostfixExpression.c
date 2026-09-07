#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int isOperator(char *token) {
    return strlen(token) == 1 &&
           (token[0] == '+' ||
            token[0] == '-' ||
            token[0] == '*' ||
            token[0] == '/');
}

int evaluatePostfix(char expression[]) {
    char *token = strtok(expression, " ");

    while (token != NULL) {

        if (isOperator(token)) {
            int b = pop();
            int a = pop();

            int result;

            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;
            }

            push(result);
        } else {
            push(atoi(token));
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char expression[] = "2 3 1 * + 9 -";

    printf("Result: %d\n", evaluatePostfix(expression));

    return 0;
}