#include <stdio.h>

#define MAXN 1005

int a[MAXN];
int temp[MAXN];

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int rounds = 0;

    while (1) {
        int moved = 0;

        for (int i = 0; i < n; i++)
            temp[i] = a[i];

        /*
         * Every element tries to move one position
         * toward its first smaller element.
         */
        for (int i = 0; i < n; i++) {

            int target = -1;

            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[i]) {
                    target = j;
                    break;
                }
            }

            if (target != -1 && target > i) {
                /*
                 * Move one position toward the target.
                 */
                temp[i] = a[i + 1];
                temp[i + 1] = a[i];
                moved = 1;
            }
        }

        if (!moved)
            break;

        for (int i = 0; i < n; i++)
            a[i] = temp[i];

        rounds++;
    }

    printf("%d\n", rounds);

    return 0;
}