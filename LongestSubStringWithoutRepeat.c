#include <stdio.h>
#include <string.h>

int longestUniqueSubstring(char str[]) {

    int lastIndex[256];

    for (int i = 0; i < 256; i++)
        lastIndex[i] = -1;

    int maxLen = 0, start = 0;

    for (int i = 0; i < strlen(str); i++) {

        if (lastIndex[str[i]] >= start)
            start = lastIndex[str[i]] + 1;

        lastIndex[str[i]] = i;

        int length = i - start + 1;

        if (length > maxLen)
            maxLen = length;
    }

    return maxLen;
}

int main() {

    char str[] = "abcabcbb";

    printf("Longest Length: %d\n",
           longestUniqueSubstring(str));

    return 0;
}