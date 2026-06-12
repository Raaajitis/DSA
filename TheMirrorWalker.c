#include <stdio.h>
#include <string.h>

int main() {

    char moves[] = "RRL";

    int pos = 0;

    for(int i=0;i<strlen(moves);i++) {

        if(moves[i] == 'R')
            pos++;

        else
            pos--;

        pos = -pos;
    }

    printf("Final Position = %d\n",
           pos);

    return 0;
}