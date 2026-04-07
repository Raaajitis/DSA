#include <stdio.h>

#define MAX 100

int maxHeap[MAX], minHeap[MAX];
int maxSize = 0, minSize = 0;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// Max heap insert
void insertMax(int x) {
    int i = maxSize++;
    maxHeap[i] = x;

    while (i > 0 && maxHeap[(i-1)/2] < maxHeap[i]) {
        swap(&maxHeap[i], &maxHeap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Min heap insert
void insertMin(int x) {
    int i = minSize++;
    minHeap[i] = x;

    while (i > 0 && minHeap[(i-1)/2] > minHeap[i]) {
        swap(&minHeap[i], &minHeap[(i-1)/2]);
        i = (i-1)/2;
    }
}

double getMedian() {

    if (maxSize == minSize)
        return (maxHeap[0] + minHeap[0]) / 2.0;
    else
        return maxHeap[0];
}

int main() {

    insertMax(5);
    insertMin(15);

    printf("Median: %.2f\n", getMedian());

    return 0;
}