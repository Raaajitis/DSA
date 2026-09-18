#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    long long k;

    scanf("%d %lld", &n, &k);

    long long *array = malloc(n * sizeof(long long));
    int *maximumDeque = malloc(n * sizeof(int));
    int *minimumDeque = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &array[i]);
    }

    int maxFront = 0;
    int maxBack = 0;

    int minFront = 0;
    int minBack = 0;

    int left = 0;
    int answer = 0;

    for (int right = 0; right < n; right++) {
        /*
         * Maintain a decreasing deque for maximum values.
         */
        while (maxFront < maxBack &&
               array[maximumDeque[maxBack - 1]] <= array[right]) {
            maxBack--;
        }

        maximumDeque[maxBack++] = right;

        /*
         * Maintain an increasing deque for minimum values.
         */
        while (minFront < minBack &&
               array[minimumDeque[minBack - 1]] >= array[right]) {
            minBack--;
        }

        minimumDeque[minBack++] = right;

        while (array[maximumDeque[maxFront]] -
               array[minimumDeque[minFront]] > k) {

            if (maximumDeque[maxFront] == left) {
                maxFront++;
            }

            if (minimumDeque[minFront] == left) {
                minFront++;
            }

            left++;
        }

        int currentLength = right - left + 1;

        if (currentLength > answer) {
            answer = currentLength;
        }
    }

    printf("%d\n", answer);

    free(array);
    free(maximumDeque);
    free(minimumDeque);

    return 0;
}