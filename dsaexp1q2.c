#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i, j, x; 


    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a1[n + 1]; 


    printf("Enter %d elements:\n", n);
    for (int k = 0; k < n; k++) {
        scanf("%d", &a1[k]);
    }


    printf("Enter the element to insert and its position: ");
    scanf("%d%d", &x, &i);


    for (int k = n; k > i; k--) {
        a1[k] = a1[k - 1];
    }

    a1[i] = x; 
    n++; 


    printf("Array after insertion:\n");
    printArray(a1, n);

    
    printf("Enter the position to delete: ");
    scanf("%d", &j);


    for (int k = j; k < n - 1; k++) {
        a1[k] = a1[k + 1];
    }

    n--; 

    
    printf("Array after deletion:\n");
    printArray(a1, n);

    return 0;
}