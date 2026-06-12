#include <stdio.h>

int main() {

    int arr[] = {5,2,5,7,2,5};
    int n = 6;

    int freq[100] = {0};

    for(int i=0;i<n;i++)
        freq[arr[i]]++;

    printf("Alive Numbers:\n");

    for(int i=0;i<100;i++) {

        if(freq[i] % 2 == 1)
            printf("%d ", i);
    }

    return 0;
}