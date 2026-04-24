#include <stdio.h>
#include <string.h>

void compress(char str[]) {

    int n = strlen(str);
    char result[100];
    int k = 0;

    for (int i = 0; i < n; i++) {

        int count = 1;

        while (i < n - 1 && str[i] == str[i+1]) {
            count++;
            i++;
        }

        result[k++] = str[i];
        result[k++] = count + '0';
    }

    result[k] = '\0';

    printf("%s\n", result);
}

int main() {

    char str[] = "aaabbc";

    compress(str);

    return 0;
}