#include <stdio.h>
#include <string.h>

void removeKDigits(char s[], int k) {
    char stack[1000];
    int top = -1;
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        while (top != -1 && stack[top] > s[i] && k > 0) {
            top--;
            k--;
        }
        stack[++top] = s[i];
    }

    // If still digits to remove (ascending case)
    while (k > 0 && top != -1) {
        top--;
        k--;
    }

    // Build result (skip leading zeros)
    int i = 0, j = 0;
    while (i <= top && stack[i] == '0') i++;

    if (i > top) {
        printf("0\n");
        return;
    }

    while (i <= top) {
        printf("%c", stack[i]);
        i++;
    }
    printf("\n");
}

int main() {
    char s[] = "1432219";
    int k = 3;
    removeKDigits(s, k);
    return 0;
}