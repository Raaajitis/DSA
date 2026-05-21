#include <stdio.h>
#include <string.h>

void gravityFlip(char str[]) {

    int n = strlen(str);
    int start = 0;

    while (start < n) {

        int end = start;

        while (end < n && str[end] != '|')
            end++;

        int stones = 0;

        for (int i = start; i < end; i++) {
            if (str[i] == '#')
                stones++;
        }

        for (int i = start; i < end; i++)
            str[i] = '.';

        for (int i = end - stones; i < end; i++)
            str[i] = '#';

        start = end + 1;
    }

    printf("%s\n", str);
}

int main() {

    char str[] = "#.#..|##..";

    gravityFlip(str);

    return 0;
}