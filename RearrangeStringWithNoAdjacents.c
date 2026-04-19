#include <stdio.h>
#include <string.h>

void rearrange(char str[]) {

    int freq[26] = {0};
    int n = strlen(str);

    for (int i = 0; i < n; i++)
        freq[str[i] - 'a']++;

    char result[100];
    int index = 0;

    while (index < n) {

        int max = 0;
        for (int i = 1; i < 26; i++)
            if (freq[i] > freq[max])
                max = i;

        if (freq[max] == 0)
            break;

        result[index++] = max + 'a';
        freq[max]--;

        // block reuse immediately
        if (index < n) {
            int second = -1;
            for (int i = 0; i < 26; i++)
                if (i != max && freq[i] > 0) {
                    second = i;
                    break;
                }

            if (second == -1 && freq[max] > 0) {
                printf("Not possible\n");
                return;
            }

            if (second != -1) {
                result[index++] = second + 'a';
                freq[second]--;
            }
        }
    }

    result[n] = '\0';
    printf("%s\n", result);
}

int main() {

    char str[] = "aaabbc";
    rearrange(str);

    return 0;
}