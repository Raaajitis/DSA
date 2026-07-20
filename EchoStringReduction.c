#include <stdio.h>
#include <string.h>

void reverse(char s[]) {

    int n = strlen(s);

    for(int i = 0; i < n/2; i++) {

        char temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }
}

int main() {

    char s[200];

    scanf("%s", s);

    while(1) {

        int n = strlen(s);
        int found = 0;

        for(int i = 0; i < n-1; i++) {

            if(s[i] == s[i+1]) {

                for(int j = i; j < n-2; j++)
                    s[j] = s[j+2];

                s[n-2] = '\0';

                reverse(s);

                found = 1;
                break;
            }
        }

        if(!found)
            break;
    }

    printf("%s\n", s);

    return 0;
}