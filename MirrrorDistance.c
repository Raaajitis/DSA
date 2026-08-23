#include <stdio.h>
#include <string.h>

#define MAXN 100005

int main() {

    char s[MAXN];

    scanf("%s", s);

    int n = strlen(s);

    int left = 0;
    int right = n - 1;

    int pairs = 0;

    while (left < right) {

        if (s[left] == s[right])
            pairs++;

        left++;
        right--;
    }

    printf("%d\n", pairs);

    return 0;
}