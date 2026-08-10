#include <stdio.h>

#define MAXN 100005

int a[MAXN];
int next[MAXN];

int main() {

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n - 1; i++)
        next[i] = i + 1;

    next[n - 1] = -1;

    int size = n;
    long long removedSum = 0;

    while (1) {

        int current = 0;
        int found = 0;

        while (current != -1) {

            int right = next[current];

            if (right != -1 && a[current] > a[right]) {

                /*
                 * current and right form
                 * the leftmost inversion.
                 *
                 * Remove the second element.
                 */
                removedSum += a[right];

                next[current] = next[right];

                size--;
                found = 1;

                break;
            }

            current = right;
        }

        if (!found)
            break;
    }

    printf("%d %lld\n", size, removedSum);

    return 0;
}