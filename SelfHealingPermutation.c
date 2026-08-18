#include <stdio.h>

#define MAXN 100005

int p[MAXN];
int visited[MAXN];

int main() {

    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    int cycles = 0;

    for (int i = 1; i <= n; i++) {

        if (visited[i])
            continue;

        cycles++;

        int current = i;

        while (!visited[current]) {

            visited[current] = 1;

            current = p[current];
        }
    }

    long long answer =
        (long long)n - cycles;

    printf("%lld\n", answer);

    return 0;
}