#include <stdio.h>

#define MAX 100

void stream(char str[]) {

    int freq[26] = {0};
    char queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; str[i]; i++) {

        char ch = str[i];
        freq[ch - 'a']++;

        queue[rear++] = ch;

        while (front < rear && freq[queue[front] - 'a'] > 1)
            front++;

        if (front < rear)
            printf("%c ", queue[front]);
        else
            printf("-1 ");
    }
}

int main() {

    char str[] = "aabc";

    stream(str);

    return 0;
}