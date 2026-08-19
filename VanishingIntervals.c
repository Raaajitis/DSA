#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct {
    long long x;
    int type;
    int id;
} Event;

int compareEvents(const void *a, const void *b) {

    Event *x = (Event *)a;
    Event *y = (Event *)b;

    if (x->x != y->x)
        return (x->x > y->x) - (x->x < y->x);

    /*
     * At the same coordinate:
     * start events before end events.
     */
    return x->type - y->type;
}

long long L[MAXN];
long long R[MAXN];

int main() {

    int n;
    scanf("%d", &n);

    Event *events =
        malloc(2LL * n * sizeof(Event));

    for (int i = 0; i < n; i++) {

        scanf("%lld %lld", &L[i], &R[i]);

        /*
         * type 0 = start
         * type 1 = end
         */
        events[2 * i].x = L[i];
        events[2 * i].type = 0;
        events[2 * i].id = i;

        events[2 * i + 1].x = R[i];
        events[2 * i + 1].type = 1;
        events[2 * i + 1].id = i;
    }

    qsort(events, 2 * n, sizeof(Event), compareEvents);

    /*
     * A simpler way to determine whether an interval
     * has a unique point is to coordinate-compress all
     * endpoints and calculate coverage on each segment.
     */

    long long *coords =
        malloc(2LL * n * sizeof(long long));

    for (int i = 0; i < n; i++) {
        coords[2 * i] = L[i];
        coords[2 * i + 1] = R[i];
    }

    qsort(coords, 2 * n, sizeof(long long),
          compareEvents);

    int m = 0;

    for (int i = 0; i < 2 * n; i++) {

        if (i == 0 || coords[i] != coords[i - 1])
            coords[m++] = coords[i];
    }

    /*
     * Difference array for coverage.
     */
    int *diff =
        calloc(m + 1, sizeof(int));

    for (int i = 0; i < n; i++) {

        int left = 0;
        int right = m - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (coords[mid] < L[i])
                left = mid + 1;
            else
                right = mid;
        }

        int li = left;

        left = 0;
        right = m - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (coords[mid] < R[i])
                left = mid + 1;
            else
                right = mid;
        }

        int ri = left;

        diff[li]++;
        diff[ri]--;
    }

    /*
     * coverage[i] = number of intervals covering
     * the segment [coords[i], coords[i+1]].
     */
    int *coverage =
        malloc(m * sizeof(int));

    int current = 0;

    for (int i = 0; i < m; i++) {

        current += diff[i];

        coverage[i] = current;
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {

        int left = 0;
        int right = m - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (coords[mid] < L[i])
                left = mid + 1;
            else
                right = mid;
        }

        int li = left;

        left = 0;
        right = m - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (coords[mid] < R[i])
                left = mid + 1;
            else
                right = mid;
        }

        int ri = left;

        int vanishing = 0;

        /*
         * Check whether some segment inside this
         * interval has coverage exactly 1.
         */
        for (int j = li; j < ri; j++) {

            if (coverage[j] == 1) {
                vanishing = 1;
                break;
            }
        }

        if (vanishing)
            answer++;
    }

    printf("%d\n", answer);

    free(events);
    free(coords);
    free(diff);
    free(coverage);

    return 0;
}