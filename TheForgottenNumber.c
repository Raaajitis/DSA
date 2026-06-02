#include <stdio.h>

#define MAX 100

int main() {

    int arr[] = {1,1,1,2,2,3,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int freq[MAX] = {0};

    for(int i = 0; i < n; i++)
        freq[arr[i]]++;

    int distinct = 0;

    for(int i = 0; i < MAX; i++)
        if(freq[i] > 0)
            distinct++;

    int time = 0;

    while(distinct > 1) {

        int maxFreq = 0;

        for(int i = 0; i < MAX; i++)
            if(freq[i] > maxFreq)
                maxFreq = freq[i];

        for(int i = 0; i < MAX; i++) {

            if(freq[i] == maxFreq) {

                freq[i] = 0;
                distinct--;
            }
        }

        time++;
    }

    for(int i = 0; i < MAX; i++) {

        if(freq[i] > 0) {

            printf("Survivor = %d\n", i);
            printf("Time = %d\n", time);
        }
    }

    return 0;
}