#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef long long ll;

const ll MOD1 = 1000000007LL;
const ll MOD2 = 1000000009LL;
const ll BASE = 911382323LL;

ll pow1[MAXN * 2];
ll pow2[MAXN * 2];

ll hashA1[MAXN * 2];
ll hashA2[MAXN * 2];

ll hashB1[MAXN];
ll hashB2[MAXN];

ll A[MAXN];
ll B[MAXN];

ll getHash(ll prefix[], ll power[],
           int l, int r, ll mod) {

    /*
     * Hash of [l, r)
     */
    ll result =
        (prefix[r] -
         prefix[l] * power[r - l]) % mod;

    if (result < 0)
        result += mod;

    return result;
}

int equalRange(int startA, int startB,
               int length) {

    if (length == 0)
        return 1;

    ll a1 =
        getHash(hashA1, pow1,
                startA,
                startA + length,
                MOD1);

    ll b1 =
        getHash(hashB1, pow1,
                startB,
                startB + length,
                MOD1);

    if (a1 != b1)
        return 0;

    ll a2 =
        getHash(hashA2, pow2,
                startA,
                startA + length,
                MOD2);

    ll b2 =
        getHash(hashB2, pow2,
                startB,
                startB + length,
                MOD2);

    return a2 == b2;
}

int main() {

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%lld", &A[i]);

    for (int i = 0; i < n; i++)
        scanf("%lld", &B[i]);

    /*
     * Build A + A.
     */
    for (int i = 0; i < n; i++)
        A[n + i] = A[i];

    int total = 2 * n;

    pow1[0] = 1;
    pow2[0] = 1;

    for (int i = 1; i <= total; i++) {

        pow1[i] =
            (pow1[i - 1] * BASE) % MOD1;

        pow2[i] =
            (pow2[i - 1] * BASE) % MOD2;
    }

    /*
     * Prefix hashes for A + A.
     */
    hashA1[0] = 0;
    hashA2[0] = 0;

    for (int i = 0; i < total; i++) {

        hashA1[i + 1] =
            (hashA1[i] * BASE +
             A[i]) % MOD1;

        hashA2[i + 1] =
            (hashA2[i] * BASE +
             A[i]) % MOD2;
    }

    /*
     * Prefix hashes for B.
     */
    hashB1[0] = 0;
    hashB2[0] = 0;

    for (int i = 0; i < n; i++) {

        hashB1[i + 1] =
            (hashB1[i] * BASE +
             B[i]) % MOD1;

        hashB2[i + 1] =
            (hashB2[i] * BASE +
             B[i]) % MOD2;
    }

    /*
     * Try rotations from smallest to largest.
     */
    for (int k = 0; k < n; k++) {

        /*
         * Find longest common prefix.
         */
        int low = 0;
        int high = n;

        while (low < high) {

            int mid =
                low + (high - low + 1) / 2;

            if (equalRange(k, 0, mid))
                low = mid;
            else
                high = mid - 1;
        }

        int prefix = low;

        /*
         * If everything matches, this is NOT valid
         * because exactly one element must be corrupted.
         */
        if (prefix == n)
            continue;

        /*
         * Find longest matching suffix after
         * the first mismatch.
         */
        int remaining = n - prefix - 1;

        low = 0;
        high = remaining;

        while (low < high) {

            int mid =
                low + (high - low + 1) / 2;

            int startA =
                k + n - mid;

            int startB =
                n - mid;

            if (equalRange(startA,
                           startB,
                           mid)) {

                low = mid;

            } else {
                high = mid - 1;
            }
        }

        int suffix = low;

        /*
         * Prefix + one corrupted element + suffix
         * must cover the entire array.
         */
        if (prefix + suffix + 1 == n) {

            printf("%d\n", k);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}