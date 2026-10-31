#include <stdio.h>
#include <string.h>

#define MAX 100

int rearrangeString(char str[]) {

    int frequency[26] = {0};

    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        frequency[str[i] - 'a']++;
    }

    char result[MAX];

    int previous = -1;

    for (int position = 0; position < n; position++) {

        int best = -1;

        // Find most frequent character
        // different from previous character
        for (int i = 0; i < 26; i++) {

            if (i != previous &&
                frequency[i] > 0) {

                if (best == -1 ||
                    frequency[i] > frequency[best]) {

                    best = i;
                }
            }
        }

        // No valid character can be placed
        if (best == -1) {
            return 0;
        }

        result[position] = 'a' + best;

        frequency[best]--;

        previous = best;
    }

    result[n] = '\0';

    printf("Rearranged string: %s\n", result);

    return 1;
}

int main() {

    char str[] = "aaabc";

    if (!rearrangeString(str)) {

        printf("Rearrangement is impossible.\n");
    }

    return 0;
}