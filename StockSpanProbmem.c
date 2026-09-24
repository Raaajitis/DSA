#include <stdio.h>

void calculateSpan(int price[], int n) {
    int stack[n];
    int span[n];
    int top = -1;

    for (int i = 0; i < n; i++) {

        while (top >= 0 && price[stack[top]] <= price[i])
            top--;

        if (top == -1)
            span[i] = i + 1;
        else
            span[i] = i - stack[top];

        stack[++top] = i;
    }

    printf("Stock Spans: ");

    for (int i = 0; i < n; i++)
        printf("%d ", span[i]);

    printf("\n");
}

int main() {
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);

    calculateSpan(price, n);

    return 0;
}