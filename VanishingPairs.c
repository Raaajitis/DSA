#include <stdio.h>

#define MAXN 100005

int stack[MAXN];
int top = -1;

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        if (top >= 0 && stack[top] == x) {
            // Adjacent equal pair disappears
            top--;
        } else {
            stack[++top] = x;
        }
    }

    printf("%d\n", top + 1);

    return 0;
}