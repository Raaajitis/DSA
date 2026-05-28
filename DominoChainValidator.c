#include <stdio.h>

int canChain(int arr[][2], int n) {

    int used[100] = {0};
    int end = arr[0][1];

    used[0] = 1;
    int count = 1;

    while (count < n) {

        int found = 0;

        for (int i = 1; i < n; i++) {

            if (!used[i]) {

                if (arr[i][0] == end) {

                    end = arr[i][1];
                    used[i] = 1;
                    found = 1;
                    count++;
                    break;
                }

                else if (arr[i][1] == end) {

                    end = arr[i][0];
                    used[i] = 1;
                    found = 1;
                    count++;
                    break;
                }
            }
        }

        if (!found)
            return 0;
    }

    return 1;
}

int main() {

    int arr[][2] = {
        {1,2},
        {3,2},
        {3,4}
    };

    int n = 3;

    if (canChain(arr,n))
        printf("Possible\n");
    else
        printf("Not Possible\n");

    return 0;
}