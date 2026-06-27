#include <stdio.h>
#include <string.h>

int main() {

    char s[] = "abacba";
    char result[100] = "";
    int seen[256] = {0};

    int len = 0;

    for(int i = 0; s[i]; i++) {

        if(seen[(unsigned char)s[i]]) {

            for(int l = 0, r = len - 1; l < r; l++, r--) {
                char temp = result[l];
                result[l] = result[r];
                result[r] = temp;
            }
        }

        result[len++] = s[i];
        result[len] = '\0';

        seen[(unsigned char)s[i]] = 1;
    }

    printf("%s\n", result);

    return 0;
}