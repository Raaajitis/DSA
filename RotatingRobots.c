#include <stdio.h>

#define MAXN 100005

int blocked[MAXN];
int alive[MAXN];

int main() {

    int n, k, q;

    scanf("%d %d %d", &n, &k, &q);

    /*
     * Initial blocked states.
     */
    for (int i = 0; i < n; i++)
        scanf("%d", &blocked[i]);

    /*
     * Initially every robot is alive.
     */
    for (int i = 0; i < n; i++)
        alive[i] = 1;

    int aliveCount = n;

    /*
     * current position of robot i.
     *
     * Initially robot i is at position i.
     */
    int position[MAXN];

    for (int i = 0; i < n; i++)
        position[i] = i;

    while (q--) {

        int type;

        scanf("%d", &type);

        if (type == 1) {

            int x;

            scanf("%d", &x);

            /*
             * Toggle blocked/unblocked.
             */
            blocked[x] ^= 1;

        } else {

            /*
             * Move every currently alive robot.
             */
            for (int i = 0; i < n; i++) {

                if (!alive[i])
                    continue;

                position[i] =
                    (position[i] + k) % n;

                /*
                 * Robot disappears if it lands
                 * on a blocked position.
                 */
                if (blocked[position[i]]) {

                    alive[i] = 0;
                    aliveCount--;
                }
            }

            printf("%d\n", aliveCount);
        }
    }

    return 0;
}