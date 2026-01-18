#include <stdio.h>

int main() {
    int n, i, found = 0;
    float search;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%f", &search);

    for (i = 0; i < n; i++) {
        if (arr[i] == search) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Number found at position %d.\n", i + 1);
    } else {
        printf("Number not found in the array.\n");
    }

    return 0;
}