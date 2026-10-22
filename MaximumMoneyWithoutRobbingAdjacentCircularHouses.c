#include <stdio.h>

int max(int a, int b) {

    if (a > b) {
        return a;
    }

    return b;
}

int robLinear(int money[], int start, int end) {

    int previousPrevious = 0;
    int previous = 0;

    for (int i = start; i <= end; i++) {

        int robCurrent =
            previousPrevious + money[i];

        int skipCurrent =
            previous;

        int current =
            max(robCurrent, skipCurrent);

        previousPrevious = previous;
        previous = current;
    }

    return previous;
}

int robCircular(int money[], int n) {

    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return money[0];
    }

    // Case 1: Ignore last house
    int case1 =
        robLinear(money, 0, n - 2);

    // Case 2: Ignore first house
    int case2 =
        robLinear(money, 1, n - 1);

    return max(case1, case2);
}

int main() {

    int money[] = {1, 2, 3, 1};

    int n =
        sizeof(money) / sizeof(money[0]);

    int result =
        robCircular(money, n);

    printf("Maximum money that can be robbed: %d\n",
           result);

    return 0;
}