// File: longest_substring_k_distinct.c
#include <stdio.h>
#include <string.h>

int longestKDistinct(char s[], int K) {
    int freq[256] = {0};
    int left = 0, count = 0, ans = 0;
    int n = strlen(s);

    for (int right = 0; right < n; right++) {
        if (freq[(unsigned char)s[right]] == 0)
            count++;  // new distinct char
        
        freq[(unsigned char)s[right]]++;

        while (count > K) {
            freq[(unsigned char)s[left]]--;
            if (freq[(unsigned char)s[left]] == 0)
                count--;
            left++;
        }

        if (right - left + 1 > ans)
            ans = right - left + 1;
    }

    return ans;
}

int main() {
    char s[] = "abaccc";
    int K = 2;

    printf("Longest length = %d\n", longestKDistinct(s, K));
    return 0;
}