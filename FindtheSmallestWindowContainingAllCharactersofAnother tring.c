#include <stdio.h>
#include <string.h>
#include <limits.h>

void smallestWindow(char text[], char pattern[]) {

    int required[256] = {0};
    int window[256] = {0};

    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    if (patternLength > textLength) {
        printf("No valid window exists.\n");
        return;
    }

    for (int i = 0; i < patternLength; i++) {
        required[(unsigned char)pattern[i]]++;
    }

    int left = 0;
    int matched = 0;

    int minLength = INT_MAX;
    int startIndex = -1;

    for (int right = 0; right < textLength; right++) {

        unsigned char current = text[right];

        window[current]++;

        if (required[current] > 0 &&
            window[current] <= required[current]) {

            matched++;
        }

        // Current window contains the whole pattern
        while (matched == patternLength) {

            int currentLength = right - left + 1;

            if (currentLength < minLength) {

                minLength = currentLength;
                startIndex = left;
            }

            unsigned char leftChar = text[left];

            window[leftChar]--;

            if (required[leftChar] > 0 &&
                window[leftChar] < required[leftChar]) {

                matched--;
            }

            left++;
        }
    }

    if (startIndex == -1) {

        printf("No valid window exists.\n");
        return;
    }

    printf("Smallest window: ");

    for (int i = startIndex;
         i < startIndex + minLength;
         i++) {

        printf("%c", text[i]);
    }

    printf("\n");
}

int main() {

    char text[] = "ADOBECODEBANC";
    char pattern[] = "ABC";

    smallestWindow(text, pattern);

    return 0;
}