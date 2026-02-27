#include <stdio.h>
#include <string.h>

#define MAX 1000

void firstNonRepeating(char stream[]) {
    int freq[26] = {0};
    char queue[MAX];
    int front = 0, rear = 0;

    int n = strlen(stream);

    for (int i = 0; i < n; i++) {
        char ch = stream[i];

        // Increase frequency
        freq[ch - 'a']++;

        // Push into queue
        queue[rear++] = ch;

        // Remove repeating characters from front
        while (front < rear && freq[queue[front] - 'a'] > 1) {
            front++;
        }

        // Print result
        if (front < rear)
            printf("%c ", queue[front]);
        else
            printf("-1 ");
    }
}

int main() {
    char stream[] = "aabcbd";
    firstNonRepeating(stream);
    return 0;
}