#include <stdio.h>

int main() {

    int arr[] = {3,1,3,2,3,1,3};
    int n = 7;

    int best = 0;

    for(int l=0;l<n;l++) {

        int freq[100] = {0};

        for(int r=l;r<n;r++) {

            freq[arr[r]]++;

            if(arr[l] != arr[r])
                continue;

            int target = arr[l];

            int valid = 1;

            for(int k=0;k<100;k++) {

                if(k != target &&
                   freq[k] >= freq[target]) {

                    valid = 0;
                    break;
                }
            }

            if(valid &&
               r-l+1 > best)
                best = r-l+1;
        }
    }

    printf("%d\n", best);

    return 0;
}