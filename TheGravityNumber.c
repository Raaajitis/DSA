#include <stdio.h>
#include <string.h>

int main() {

    char num[] = "10230405";

    int n = strlen(num);

    char result[100];

    int pos = n - 1;

    for(int i = n - 1; i >= 0; i--) {

        if(num[i] != '0')
            result[pos--] = num[i];
    }

    while(pos >= 0)
        result[pos--] = '0';

    result[n] = '\0';

    printf("%s\n", result);

    return 0;
}