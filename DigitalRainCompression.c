#include <stdio.h>
#include <string.h>

void compress(char str[]) {

    int n = strlen(str);

    for (int len = n / 2; len >= 1; len--) {

        int i = 0;

        while (i < n) {

            int count = 1;

            while (i + count * len + len <= n &&
                   strncmp(str + i,
                           str + i + count * len,
                           len) == 0) {

                count++;
            }

            if (count > 1) {

                printf("%d[", count);

                for (int k = 0; k < len; k++)
                    printf("%c", str[i + k]);

                printf("]");

                i += count * len;
            }
            else {
                printf("%c", str[i]);
                i++;
            }
        }

        printf("\n");
        return;
    }
}

int main() {

    char str[] = "abcabcabcxyzxyz";

    compress(str);

    return 0;
}