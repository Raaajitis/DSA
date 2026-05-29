#include <stdio.h>

int main() {

    int N = 10;
    int pos = 2;
    int moves = 8;

    int dir = 1;

    for (int i = 1; i <= moves; i++) {

        pos = (pos + dir + N) % N;

        if (i % 3 == 0)
            dir *= -1;
    }

    printf("Final Position: %d\n", pos);

    return 0;
}