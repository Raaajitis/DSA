#include <stdio.h>
#include <string.h>

char firstNonRepeating(char str[]) {

    int frequency[26] = {0};

    int length = strlen(str);

    // Count frequency of each character
    for (int i = 0; i < length; i++) {

        int index = str[i] - 'a';

        frequency[index]++;
    }

    // Find the first character having frequency 1
    for (int i = 0; i < length; i++) {

        int index = str[i] - 'a';

        if (frequency[index] == 1) {
            return str[i];
        }
    }

    return '\0';
}

int main() {

    char str[] = "swiss";

    char result = firstNonRepeating(str);

    if (result != '\0') {

        printf("First non-repeating character: %c\n", result);

    } else {

        printf("No non-repeating character exists.\n");
    }

    return 0;
}