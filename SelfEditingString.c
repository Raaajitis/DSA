#include <stdio.h>
#include <string.h>

int main() {

    char stream[100] = "XA";

    char result[200];
    int r = 0;

    for(int i=0; stream[i] != '\0'; i++) {

        char ch = stream[i];

        if(ch == 'A') {

            result[r++] = 'A';

            strcat(stream, "BC");
        }

        else if(ch == 'B') {

            if(r > 0)
                r--;
        }

        else if(ch == 'C') {

            if(stream[i+1] != '\0')
                result[r++] = stream[i+1];
        }

        else {
            result[r++] = ch;
        }
    }

    result[r] = '\0';

    printf("%s\n", result);

    return 0;
}