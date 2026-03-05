#include <stdio.h>
#include <string.h>

int areAnagrams(char s1[], char s2[]) {

    int freq[26] = {0};

    if (strlen(s1) != strlen(s2))
        return 0;

    for (int i = 0; i < strlen(s1); i++) {
        freq[s1[i] - 'a']++;
        freq[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0)
            return 0;
    }

    return 1;
}

int main() {

    char s1[] = "listen";
    char s2[] = "silent";

    if (areAnagrams(s1, s2))
        printf("Strings are Anagrams\n");
    else
        printf("Strings are Not Anagrams\n");

    return 0;
}