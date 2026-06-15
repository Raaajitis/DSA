#include <stdio.h>
#include <string.h>

int main() {

    char str[] = "abcde";

    char stack[100];

    int top = -1;

    for(int i=0; str[i]; i++) {

        if(top >= 0 &&
           stack[top] + 1 == str[i]) {

            top--;
        }
        else {

            stack[++top] = str[i];
        }
    }

    stack[top + 1] = '\0';

    printf("Result = %s\n", stack);

    return 0;
}