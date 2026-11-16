#include <stdio.h>
#include <string.h>

#define MAX 1000

void largestAfterRemovingK(char num[], int k) {

    int n = strlen(num);

    if (k >= n) {
        printf("Largest number: 0\n");
        return;
    }

    char stack[MAX];
    int top = -1;

    for (int i = 0; i < n; i++) {

        while (top >= 0 &&
               k > 0 &&
               stack[top] < num[i]) {

            top--;
            k--;
        }

        stack[++top] = num[i];
    }

    /*
     * If k is still greater than zero,
     * remove digits from the end.
     */
    while (k > 0 && top >= 0) {

        top--;
        k--;
    }

    printf("Largest number: ");

    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }

    printf("\n");
}

int main() {

    char num[] = "1924";
    int k = 2;

    largestAfterRemovingK(num, k);

    return 0;
}