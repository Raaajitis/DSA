#include <stdio.h>

#define MAX 100

void jumpPath(int arr[], int n) {

    int jumps = 0, end = 0, farthest = 0;
    int parent[MAX];

    for (int i = 0; i < n; i++)
        parent[i] = -1;

    for (int i = 0; i < n - 1; i++) {

        if (i + arr[i] > farthest) {
            farthest = i + arr[i];
            parent[farthest] = i;
        }

        if (i == end) {
            jumps++;
            end = farthest;
        }
    }

    printf("Min jumps: %d\n", jumps);

    // reconstruct path
    int path[MAX], k = 0;
    int curr = n - 1;

    while (curr != -1) {
        path[k++] = curr;
        curr = parent[curr];
    }

    for (int i = k - 1; i >= 0; i--)
        printf("%d ", path[i]);
}

int main() {

    int arr[] = {2,3,1,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    jumpPath(arr, n);

    return 0;
}