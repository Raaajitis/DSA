#include <stdio.h>

void findMajorityElements(int arr[], int n) {

    int candidate1 = 0;
    int candidate2 = 1;

    int count1 = 0;
    int count2 = 0;

    // Find possible candidates
    for (int i = 0; i < n; i++) {

        if (arr[i] == candidate1) {

            count1++;
        }
        else if (arr[i] == candidate2) {

            count2++;
        }
        else if (count1 == 0) {

            candidate1 = arr[i];
            count1 = 1;
        }
        else if (count2 == 0) {

            candidate2 = arr[i];
            count2 = 1;
        }
        else {

            count1--;
            count2--;
        }
    }

    // Verify candidates
    count1 = 0;
    count2 = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] == candidate1) {
            count1++;
        }
        else if (arr[i] == candidate2) {
            count2++;
        }
    }

    int found = 0;

    printf("Elements appearing more than n/3 times: ");

    if (count1 > n / 3) {

        printf("%d ", candidate1);
        found = 1;
    }

    if (count2 > n / 3) {

        printf("%d ", candidate2);
        found = 1;
    }

    if (!found) {
        printf("None");
    }

    printf("\n");
}

int main() {

    int arr[] = {1, 2, 1, 2, 1, 2, 3};

    int n = sizeof(arr) / sizeof(arr[0]);

    findMajorityElements(arr, n);

    return 0;
}