#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start, end;
};

int compare(const void *a, const void *b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

void mergeIntervals(struct Interval arr[], int n) {

    qsort(arr, n, sizeof(struct Interval), compare);

    int index = 0;

    for (int i = 1; i < n; i++) {

        if (arr[index].end >= arr[i].start) {

            if (arr[i].end > arr[index].end)
                arr[index].end = arr[i].end;

        } else {
            index++;
            arr[index] = arr[i];
        }
    }

    printf("Merged Intervals:\n");
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", arr[i].start, arr[i].end);
    }
}

int main() {

    struct Interval arr[] = {
        {1,3}, {2,6}, {8,10}, {15,18}
    };

    int n = sizeof(arr)/sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}