#include <stdio.h>

float findMedian(int a[], int n, int b[], int m) {

    int merged[n + m];
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] < b[j])
            merged[k++] = a[i++];
        else
            merged[k++] = b[j++];
    }

    while (i < n)
        merged[k++] = a[i++];

    while (j < m)
        merged[k++] = b[j++];

    int total = n + m;

    if (total % 2 == 1)
        return merged[total / 2];
    else
        return (merged[total/2 - 1] + merged[total/2]) / 2.0;
}

int main() {

    int a[] = {1, 3};
    int b[] = {2};

    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);

    printf("Median: %.2f\n", findMedian(a,n,b,m));

    return 0;
}