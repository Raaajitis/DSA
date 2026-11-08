#include <stdio.h>

void daysUntilWarmer(int temperature[], int n) {

    int stack[n];
    int result[n];

    int top = -1;

    for (int i = 0; i < n; i++) {
        result[i] = 0;
    }

    for (int i = 0; i < n; i++) {

        while (top >= 0 &&
               temperature[i] >
               temperature[stack[top]]) {

            int previousDay = stack[top--];

            result[previousDay] =
                i - previousDay;
        }

        stack[++top] = i;
    }

    printf("Days to wait: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");
}

int main() {

    int temperature[] =
        {73, 74, 75, 71, 69, 72, 76, 73};

    int n =
        sizeof(temperature) / sizeof(temperature[0]);

    daysUntilWarmer(temperature, n);

    return 0;
}