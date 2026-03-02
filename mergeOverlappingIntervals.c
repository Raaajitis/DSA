#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

// Comparator for qsort
int compare(const void* a, const void* b) {
    struct Interval* i1 = (struct Interval*)a;
    struct Interval* i2 = (struct Interval*)b;
    return i1->start - i2->start;
}

void mergeIntervals(struct Interval arr[], int n) {
    if (n <= 0)
        return;

    qsort(arr, n, sizeof(struct Interval), compare);

    int index = 0;  // Index of last merged interval

    for (int i = 1; i < n; i++) {
        if (arr[index].end >= arr[i].start) {
            // Overlapping → merge
            if (arr[i].end > arr[index].end)
                arr[index].end = arr[i].end;
        } else {
            index++;
            arr[index] = arr[i];
        }
    }

    printf("Merged Intervals:\n");
    for (int i = 0; i <= index; i++)
        printf("[%d, %d] ", arr[i].start, arr[i].end);
}

int main() {
    struct Interval arr[] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeIntervals(arr, n);
    return 0;
}