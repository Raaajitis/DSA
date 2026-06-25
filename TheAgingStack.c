#include <stdio.h>

typedef struct {
    int value;
    int age;
} Item;

int main() {

    Item stack[100];
    int top = -1;

    char ops[][10] = {
        "P10", "P20", "P30", "POP", "P40"
    };

    int totalOps = 5;

    for(int op = 0; op < totalOps; op++) {

        /* Age everything */
        for(int i = 0; i <= top; i++)
            stack[i].age++;

        /* Remove expired elements */
        int i = 0;
        while(i <= top) {

            if(stack[i].age >= 5) {

                for(int j = i; j < top; j++)
                    stack[j] = stack[j+1];

                top--;
            }
            else {
                i++;
            }
        }

        if(ops[op][0] == 'P' &&
           ops[op][1] != 'O') {

            int val;
            sscanf(ops[op] + 1, "%d", &val);

            stack[++top].value = val;
            stack[top].age = 0;
        }
        else {

            if(top >= 0)
                top--;
        }
    }

    printf("Stack:\n");

    for(int i = top; i >= 0; i--)
        printf("%d(age=%d)\n",
               stack[i].value,
               stack[i].age);

    return 0;
}