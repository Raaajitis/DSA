#include <stdio.h>
#include <string.h>

int isCircular(char str[]) {

    char words[100][100];
    int count = 0;

    char *token = strtok(str, " ");

    while (token != NULL) {

        strcpy(words[count++], token);
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < count; i++) {

        char last =
            words[i][strlen(words[i]) - 1];

        char first =
            words[(i + 1) % count][0];

        if (last != first)
            return 0;
    }

    return 1;
}

int main() {

    char str[] = "king goat tap pan";

    if (isCircular(str))
        printf("Circular\n");
    else
        printf("Not Circular\n");

    return 0;
}