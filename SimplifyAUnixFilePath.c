#include <stdio.h>
#include <string.h>

#define MAX_PARTS 100
#define MAX_NAME 100

void simplifyPath(char path[]) {

    char stack[MAX_PARTS][MAX_NAME];
    int top = -1;

    int i = 0;
    int n = strlen(path);

    while (i < n) {

        // Skip '/'
        while (i < n && path[i] == '/') {
            i++;
        }

        if (i >= n) {
            break;
        }

        char directory[MAX_NAME];
        int j = 0;

        // Extract directory name
        while (i < n && path[i] != '/') {

            directory[j++] = path[i];
            i++;
        }

        directory[j] = '\0';

        // Ignore current directory
        if (strcmp(directory, ".") == 0) {
            continue;
        }

        // Move to parent
        if (strcmp(directory, "..") == 0) {

            if (top >= 0) {
                top--;
            }
        }

        // Normal directory
        else {

            top++;

            strcpy(stack[top], directory);
        }
    }

    // Root directory
    if (top == -1) {

        printf("/\n");
        return;
    }

    // Construct simplified path
    for (int i = 0; i <= top; i++) {

        printf("/%s", stack[i]);
    }

    printf("\n");
}

int main() {

    char path[] =
        "/home//user/../docs/./files/";

    printf("Simplified path: ");

    simplifyPath(path);

    return 0;
}