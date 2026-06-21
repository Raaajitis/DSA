#include <stdio.h>

int main() {

    int redFlipped = 0;
    int blueFlipped = 0;

    char moves[] = {'R','B','R'};

    for(int i = 0; i < 3; i++) {

        if(moves[i] == 'R') {
            blueFlipped = !blueFlipped;
            printf("Traversed RED -> Blue edges reversed\n");
        }
        else {
            redFlipped = !redFlipped;
            printf("Traversed BLUE -> Red edges reversed\n");
        }
    }

    printf("\nFinal State:\n");
    printf("Red Reversed : %s\n", redFlipped ? "YES" : "NO");
    printf("Blue Reversed: %s\n", blueFlipped ? "YES" : "NO");

    return 0;
}