#include <stdio.h>

int main() {

    int arr[] = {5,3,5,2,3};

    int n = 5;

    int value[100];
    int size = 0;

    for(int i=0;i<n;i++) {

        int found = -1;

        for(int j=0;j<size;j++) {

            if(value[j] == arr[i]) {

                found = j;
                break;
            }
        }

        if(found == -1) {

            value[size++] = arr[i];
        }
        else {

            value[found] += arr[i];
        }
    }

    for(int i=0;i<size;i++)
        printf("%d ", value[i]);

    return 0;
}