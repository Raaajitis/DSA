#include <stdio.h>

int validateStackSequence(int pushed[],
                          int popped[],
                          int n) {

    int stack[n];
    int top = -1;

    int popIndex = 0;

    for (int i = 0; i < n; i++) {

        // Push current element
        stack[++top] = pushed[i];

        // Pop while top matches
        // the required pop sequence
        while (top >= 0 &&
               popIndex < n &&
               stack[top] == popped[popIndex]) {

            top--;
            popIndex++;
        }
    }

    // All popped elements must be matched
    return popIndex == n;
}

int main() {

    int pushed[] = {1, 2, 3, 4, 5};

    int popped[] = {4, 5, 3, 2, 1};

    int n = sizeof(pushed) / sizeof(pushed[0]);

    if (validateStackSequence(pushed, popped, n)) {

        printf("The pop sequence is valid.\n");

    } else {

        printf("The pop sequence is invalid.\n");
    }

    return 0;
}