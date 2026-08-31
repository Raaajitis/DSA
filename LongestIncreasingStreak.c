#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    long long prev;
    scanf("%lld", &prev);

    int current = 1;
    int longest = 1;

    for (int i = 1; i < n; i++) {

        long long x;
        scanf("%lld", &x);

        if (x > prev) {
            current++;
        } else {
            current = 1;
        }

        if (current > longest)
            longest = current;

        prev = x;
    }

    printf("%d\n", longest);

    return 0;
}