#include <stdio.h>

int countEcho(int arr[], int n) {

    int count = 0;

    for (int len = 2; len <= n; len += 2) {

        for (int i = 0; i + len <= n; i++) {

            int half = len / 2;
            int match = 1;

            for (int j = 0; j < half; j++) {

                if (arr[i + j] != arr[i + j + half]) {
                    match = 0;
                    break;
                }
            }

            if (match)
                count++;
        }
    }

    return count;
}

int main() {

    int arr[] = {1,2,1,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Echo Subarrays: %d\n",
           countEcho(arr,n));

    return 0;
}