#include <stdio.h>
#include <string.h>
#include <limits.h>

void minWindow(char s[], char t[]) {

    int freqT[256] = {0};
    int freqS[256] = {0};

    int required = 0;

    for (int i = 0; t[i]; i++) {
        if (freqT[t[i]] == 0)
            required++;
        freqT[t[i]]++;
    }

    int formed = 0, left = 0;
    int minLen = INT_MAX, start = 0;

    for (int right = 0; s[right]; right++) {

        freqS[s[right]]++;

        if (freqS[s[right]] == freqT[s[right]])
            formed++;

        while (left <= right && formed == required) {

            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            freqS[s[left]]--;

            if (freqS[s[left]] < freqT[s[left]])
                formed--;

            left++;
        }
    }

    if (minLen == INT_MAX)
        printf("No window found\n");
    else {
        for (int i = start; i < start + minLen; i++)
            printf("%c", s[i]);
    }
}

int main() {

    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";

    minWindow(s, t);

    return 0;
}