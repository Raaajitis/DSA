#include <stdio.h>

int getMask(int x) {

    int mask = 0;

    while (x > 0) {

        int digit = x % 10;

        mask |= (1 << digit);

        x /= 10;
    }

    return mask;
}

int main() {

    int n;
    scanf("%d", &n);

    int frequency[1024] = {0};

    for (int i = 0; i < n; i++) {

        int x;
        scanf("%d", &x);

        int mask = getMask(x);

        frequency[mask]++;
    }

    int answer = 0;

    for (int m1 = 0; m1 < 1024; m1++) {

        if (frequency[m1] == 0)
            continue;

        for (int m2 = m1; m2 < 1024; m2++) {

            if (frequency[m2] == 0)
                continue;

            if (m1 == m2 && frequency[m1] < 2)
                continue;

            int common = m1 & m2;

            int score =
                __builtin_popcount((unsigned)common);

            if (score > answer)
                answer = score;
        }
    }

    printf("%d\n", answer);

    return 0;
}