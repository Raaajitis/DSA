#include <stdio.h>
#include <string.h>

void partitionString(char s[]) {

    int last[26];

    for (int i = 0; i < 26; i++) {
        last[i] = -1;
    }

    int n = strlen(s);

    // Store last occurrence of each character
    for (int i = 0; i < n; i++) {
        last[s[i] - 'a'] = i;
    }

    int start = 0;
    int end = 0;

    printf("Partition lengths: ");

    for (int i = 0; i < n; i++) {

        int lastPosition = last[s[i] - 'a'];

        if (lastPosition > end) {
            end = lastPosition;
        }

        // Current partition can end here
        if (i == end) {

            int length = end - start + 1;

            printf("%d ", length);

            start = i + 1;
        }
    }

    printf("\n");
}

int main() {

    char s[] = "ababcbacadefegdehijhklij";

    partitionString(s);

    return 0;
}