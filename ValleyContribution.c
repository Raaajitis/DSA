#include <stdio.h>

#define MAXN 100005

int a[MAXN];
int leftGreater[MAXN];
int rightGreater[MAXN];
int stack[MAXN];

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int top = -1;

    // Nearest Greater on Left
    for(int i = 0; i < n; i++) {

        while(top >= 0 && a[stack[top]] < a[i])
            top--;

        if(top == -1)
            leftGreater[i] = -1;
        else
            leftGreater[i] = stack[top];

        stack[++top] = i;
    }

    top = -1;

    // Nearest Greater on Right
    for(int i = n - 1; i >= 0; i--) {

        while(top >= 0 && a[stack[top]] < a[i])
            top--;

        if(top == -1)
            rightGreater[i] = -1;
        else
            rightGreater[i] = stack[top];

        stack[++top] = i;
    }

    long long ans = 0;

    for(int i = 1; i < n - 1; i++) {

        if(a[i] < a[i - 1] && a[i] < a[i + 1]) {

            if(leftGreater[i] != -1 && rightGreater[i] != -1)
                ans += (rightGreater[i] - leftGreater[i]);
        }
    }

    printf("%lld\n", ans);

    return 0;
}