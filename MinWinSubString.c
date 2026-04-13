#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 256

void minWindow(char *s, char *t) {

    int need[MAX] = {0}, have[MAX] = {0};

    for (int i = 0; t[i]; i++)
        need[t[i]]++;

    int left = 0, count = 0;
    int minLen = INT_MAX, start = 0;

    for (int right = 0; s[right]; right++) {

        have[s[right]]++;

        if (need[s[right]] && have[s[right]] <= need[s[right]])
            count++;

        while (count == strlen(t)) {

            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            have[s[left]]--;
            if (need[s[left]] && have[s[left]] < need[s[left]])
                count--;

            left++;
        }
    }

    if (minLen == INT_MAX)
        printf("No window\n");
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