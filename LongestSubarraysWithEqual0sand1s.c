#include <stdio.h>

#define MAX 1000

int maxLen(int arr[], int n) {

    int sum = 0, max_length = 0;
    int hash[2*MAX] = {0}; // offset handling

    for (int i = 0; i < 2*MAX; i++)
        hash[i] = -1;

    for (int i = 0; i < n; i++) {

        if (arr[i] == 0)
            sum += -1;
        else
            sum += 1;

        if (sum == 0)
            max_length = i + 1;

        if (hash[sum + MAX] != -1) {
            int len = i - hash[sum + MAX];
            if (len > max_length)
                max_length = len;
        } else {
            hash[sum + MAX] = i;
        }
    }

    return max_length;
}

int main() {

    int arr[] = {0,1,0,1,1,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Max Length: %d\n", maxLen(arr,n));

    return 0;
}