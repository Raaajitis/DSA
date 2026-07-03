#include <stdio.h>

#define MAX 100

int main() {

    int arr[MAX];
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while(1) {

        int found = 0;

        for(int i = 0; i < n && !found; i++) {

            for(int j = i + 1; j < n && !found; j++) {

                if(arr[i] == arr[j]) {

                    arr[i] = j - i;

                    for(int k = j; k < n - 1; k++)
                        arr[k] = arr[k + 1];

                    n--;
                    found = 1;
                }
            }
        }

        if(!found)
            break;
    }

    printf("%d\n", n);

    printf("Final Array: ");

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}