#include <stdio.h>
#include <ctype.h>

#define MAX 100

int evaluatePostfix(char expression[]) {

    int stack[MAX];
    int top = -1;

    for (int i = 0;
         expression[i] != '\0';
         i++) {

        char current = expression[i];

        // Operand
        if (isdigit(current)) {

            stack[++top] = current - '0';
        }

        // Operator
        else {

            int second = stack[top--];
            int first = stack[top--];

            int result;

            switch (current) {

                case '+':
                    result = first + second;
                    break;

                case '-':
                    result = first - second;
                    break;

                case '*':
                    result = first * second;
                    break;

                case '/':
                    result = first / second;
                    break;

                default:
                    printf("Invalid operator.\n");
                    return 0;
            }

            stack[++top] = result;
        }
    }

    return stack[top];
}

int main() {

    char expression[] = "23*54*+9-";

    int result =
        evaluatePostfix(expression);

    printf("Result: %d\n", result);

    return 0;
}