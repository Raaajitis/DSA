#include <stdio.h>

struct Meeting {
    int start;
    int end;
};

void sortMeetings(struct Meeting meetings[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (meetings[j].end > meetings[j + 1].end) {

                struct Meeting temp = meetings[j];
                meetings[j] = meetings[j + 1];
                meetings[j + 1] = temp;
            }
        }
    }
}

int maximumMeetings(int start[], int end[], int n) {

    if (n == 0) {
        return 0;
    }

    struct Meeting meetings[n];

    for (int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }

    sortMeetings(meetings, n);

    int count = 1;
    int lastEnd = meetings[0].end;

    for (int i = 1; i < n; i++) {

        if (meetings[i].start >= lastEnd) {

            count++;

            lastEnd = meetings[i].end;
        }
    }

    return count;
}

int main() {

    int start[] = {1, 3, 0, 5, 8, 5};
    int end[]   = {2, 4, 6, 7, 9, 9};

    int n = sizeof(start) / sizeof(start[0]);

    int result = maximumMeetings(start, end, n);

    printf("Maximum meetings: %d\n", result);

    return 0;
}