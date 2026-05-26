#include <stdio.h>
#include <string.h>

void brokenKeyboard(char str[]) {

    char front[100] = "";
    char back[100] = "";

    char temp[100];
    int idx = 0;

    int mode = 1; // 1 = back, 0 = front

    for (int i = 0; str[i]; i++) {

        if (str[i] == '[' || str[i] == ']') {

            temp[idx] = '\0';

            if (mode == 0)
                strcat(front, temp);
            else
                strcat(back, temp);

            idx = 0;

            mode = (str[i] == ']');
        }
        else {
            temp[idx++] = str[i];
        }
    }

    temp[idx] = '\0';

    if (mode == 0)
        strcat(front, temp);
    else
        strcat(back, temp);

    printf("%s%s\n", front, back);
}

int main() {

    char str[] = "abc[de]f";

    brokenKeyboard(str);

    return 0;
}