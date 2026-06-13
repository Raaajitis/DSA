#include <stdio.h>
#include <string.h>

int main() {

    char input[] = "abacbd";

    char result[100] = "";
    int len = 0;

    for(int i=0; input[i]; i++) {

        char ch = input[i];

        int pos = -1;

        for(int j=0;j<len;j++) {

            if(result[j] == ch) {
                pos = j;
                break;
            }
        }

        if(pos != -1) {

            for(int j=pos;j<len-1;j++)
                result[j] = result[j+1];

            len--;
        }

        result[len++] = ch;
        result[len] = '\0';
    }

    printf("Final String = %s\n", result);

    return 0;
}