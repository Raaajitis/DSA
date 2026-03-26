#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

int maxProduct(int arr[], int n) {

    int maxProd = arr[0];
    int minProd = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {

        if (arr[i] < 0) {
            int temp = maxProd;
            maxProd = minProd;
            minProd = temp;
        }

        maxProd = max(arr[i], maxProd * arr[i]);
        minProd = min(arr[i], minProd * arr[i]);

        result = max(result, maxProd);
    }

    return result;
}

int main() {

    int arr[] = {2,3,-2,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Max Product: %d\n", maxProduct(arr,n));

    return 0;
}