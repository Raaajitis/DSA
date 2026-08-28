#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    int *result = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int index = 0;

    /* First place all negative numbers. */
    for (int i = 0; i < n; i++) {

        if (a[i] < 0)
            result[index++] = a[i];
    }

    /* Then place all non-negative numbers. */
    for (int i = 0; i < n; i++) {

        if (a[i] >= 0)
            result[index++] = a[i];
    }

    for (int i = 0; i < n; i++) {

        printf("%d", result[i]);

        if (i + 1 < n)
            printf(" ");
    }

    printf("\n");

    free(a);
    free(result);

    return 0;
}