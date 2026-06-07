#include <stdio.h>
#include <string.h>

int main() {

    char str[] = "abcd";

    int n = strlen(str);
    int anti = 1;

    for(int i=0;i<n/2;i++) {

        if(str[i] == str[n-1-i]) {

            anti = 0;
            break;
        }
    }

    if(anti)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}