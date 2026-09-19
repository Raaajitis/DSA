#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *string = malloc(200001 * sizeof(char));
    char *pattern = malloc(200001 * sizeof(char));

    scanf("%s", string);
    scanf("%s", pattern);

    int n = (int)strlen(string);
    int m = (int)strlen(pattern);

    int extendedLength = n + m - 1;

    char *extended =
        malloc((extendedLength + 1) * sizeof(char));

    for (int i = 0; i < extendedLength; i++) {
        extended[i] = string[i % n];
    }

    extended[extendedLength] = '\0';

    /*
     * Build the KMP longest-prefix-suffix table.
     */
    int *prefix = calloc(m, sizeof(int));

    for (int i = 1, matched = 0; i < m; i++) {
        while (matched > 0 &&
               pattern[i] != pattern[matched]) {
            matched = prefix[matched - 1];
        }

        if (pattern[i] == pattern[matched]) {
            matched++;
        }

        prefix[i] = matched;
    }

    int occurrences = 0;
    int matched = 0;

    for (int i = 0; i < extendedLength; i++) {
        while (matched > 0 &&
               extended[i] != pattern[matched]) {
            matched = prefix[matched - 1];
        }

        if (extended[i] == pattern[matched]) {
            matched++;
        }

        if (matched == m) {
            int startingPosition = i - m + 1;

            if (startingPosition < n) {
                occurrences++;
            }

            matched = prefix[matched - 1];
        }
    }

    printf("%d\n", occurrences);

    free(string);
    free(pattern);
    free(extended);
    free(prefix);

    return 0;
}