#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i, j, x, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a1[n + 1];

    printf("Enter %d elements:\n", n);
    for (int k = 0; k < n; k++) {
        scanf("%d", &a1[k]);
    }

    do {
        printf("\nChoose an operation:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the elements\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert and its position: ");
                scanf("%d%d", &x, &i);

                if (i < 0 || i > n) {
                    printf("Invalid position! Please enter a position between 0 and %d.\n", n);
                    break;
                }

                for (int k = n; k > i; k--) {
                    a1[k] = a1[k - 1];
                }

                a1[i] = x;
                n++; 

                printf("Array after insertion:\n");
                printArray(a1, n);
                break;

            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &j);

                if (j < 0 || j >= n) {
                    printf("Invalid position! Please enter a position between 0 and %d.\n", n - 1);
                    break;
                }

                for (int k = j; k < n - 1; k++) {
                    a1[k] = a1[k + 1];
                }

                n--; 

                printf("Array after deletion:\n");
                printArray(a1, n);
                break;

            case 3: 
                 printArray(a1, n);
                break;

            default: 
                printf("Invalid choice! Please choose a valid operation.\n");
        }
    } while (choice != 3);

    return 0;
}
