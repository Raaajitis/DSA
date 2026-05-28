#include <stdio.h>

struct Item {
    int value;
    int freq;
};

void sort(struct Item arr[], int n) {

    for (int i = 0; i < n-1; i++) {

        for (int j = i+1; j < n; j++) {

            if (arr[i].freq > arr[j].freq ||

               (arr[i].freq == arr[j].freq &&
                arr[i].value < arr[j].value)) {

                struct Item temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {

    int nums[] = {5,7,5,8,7,7};
    int n = 6;

    struct Item items[100];
    int size = 0;

    for (int i = 0; i < n; i++) {

        int found = 0;

        for (int j = 0; j < size; j++) {

            if (items[j].value == nums[i]) {
                items[j].freq++;
                found = 1;
                break;
            }
        }

        if (!found) {
            items[size].value = nums[i];
            items[size].freq = 1;
            size++;
        }
    }

    sort(items,size);

    printf("Priority Order:\n");

    for (int i = 0; i < size; i++)
        printf("%d ", items[i].value);

    return 0;
}