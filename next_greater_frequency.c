#include <stdio.h>

int main() {
    int arr[] = {1, 1, 2, 3, 4, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int freq[1000] = {0};
    int res[n], stack[n], top = -1;

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && freq[stack[top]] <= freq[arr[i]])
            top--;

        res[i] = (top == -1) ? -1 : stack[top];
        stack[++top] = arr[i];
    }

    for (int i = 0; i < n; i++)
        printf("%d ", res[i]);

    return 0;
}