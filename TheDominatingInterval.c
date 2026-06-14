#include <stdio.h>

int main() {

    int arr[] = {1,2,2,3,2};

    int n = 5;

    int answer = n + 1;

    for(int i=0;i<n;i++) {

        int freq[100] = {0};

        for(int j=i;j<n;j++) {

            freq[arr[j]]++;

            int len = j - i + 1;

            if(len < 2)
                continue;

            for(int k=0;k<100;k++) {

                if(freq[k] > len/2) {

                    if(len < answer)
                        answer = len;
                }
            }
        }
    }

    if(answer == n + 1)
        printf("No such interval\n");
    else
        printf("Shortest Length = %d\n",
               answer);

    return 0;
}