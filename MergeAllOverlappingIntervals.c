#include <stdio.h>

struct Interval {
    int start;
    int end;
};

void sortIntervals(struct Interval arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j].start > arr[j + 1].start) {

                struct Interval temp = arr[j];

                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void mergeIntervals(struct Interval arr[], int n) {

    if (n == 0) {
        return;
    }

    sortIntervals(arr, n);

    struct Interval merged[n];
    int count = 0;

    struct Interval current = arr[0];

    for (int i = 1; i < n; i++) {

        // Intervals overlap
        if (arr[i].start <= current.end) {

            if (arr[i].end > current.end) {
                current.end = arr[i].end;
            }
        }

        // No overlap
        else {

            merged[count++] = current;

            current = arr[i];
        }
    }

    // Store final interval
    merged[count++] = current;

    printf("Merged intervals:\n");

    for (int i = 0; i < count; i++) {

        printf("[%d, %d]\n",
               merged[i].start,
               merged[i].end);
    }
}

int main() {

    struct Interval intervals[] = {

        {1, 3},
        {2, 6},
        {8, 10},
        {9, 12},
        {15, 18}

    };

    int n =
        sizeof(intervals) / sizeof(intervals[0]);

    mergeIntervals(intervals, n);

    return 0;
}