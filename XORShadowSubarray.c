#include <stdio.h>

#define MAXN 100005

int a[MAXN];
int prefixXor[MAXN];

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        prefixXor[i + 1] = prefixXor[i] ^ a[i];
    }

    long long answer = 0;

    for (int l = 0; l < n; l++) {

        int maximum = a[l];

        for (int r = l; r < n; r++) {

            if (a[r] > maximum)
                maximum = a[r];

            int x = prefixXor[r + 1] ^ prefixXor[l];

            if (x == maximum)
                answer++;
        }
    }

    printf("%lld\n", answer);

    return 0;
}