#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct {
    int value;
    int frequency;
} Item;

int compareInt(const void *x, const void *y) {
    int a = *(const int *)x;
    int b = *(const int *)y;

    return (a > b) - (a < b);
}

int compareItem(const void *x, const void *y) {

    Item *a = (Item *)x;
    Item *b = (Item *)y;

    if (a->frequency != b->frequency)
        return b->frequency - a->frequency;

    return a->value - b->value;
}

int main() {

    int n;

    scanf("%d", &n);

    int a[MAXN];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    /*
     * Sort values to construct frequencies.
     */
    qsort(a, n, sizeof(int), compareInt);

    Item items[MAXN];

    int unique = 0;

    for (int i = 0; i < n; ) {

        int j = i;

        while (j < n && a[j] == a[i])
            j++;

        items[unique].value = a[i];
        items[unique].frequency = j - i;

        unique++;
        i = j;
    }

    /*
     * Sort by:
     * 1. Highest frequency
     * 2. Smallest value
     */
    qsort(items, unique, sizeof(Item), compareItem);

    long long totalCost = 0;

    printf("Removal order: ");

    for (int i = 0; i < unique; i++) {

        totalCost +=
            (long long)items[i].value *
            items[i].frequency;

        printf("%d", items[i].value);

        if (i + 1 < unique)
            printf(" ");
    }

    printf("\n");

    printf("Total cost: %lld\n", totalCost);

    return 0;
}