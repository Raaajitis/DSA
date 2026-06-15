#include <stdio.h>

int main() {

    int n = 5;

    int alive[100];

    for(int i=0;i<n;i++)
        alive[i] = i + 1;

    int size = n;
    int pos = 0;
    int step = 1;

    while(size > 1) {

        pos = (pos + step - 1) % size;

        for(int i=pos;i<size-1;i++)
            alive[i] = alive[i+1];

        size--;

        step++;

        if(size > 0)
            pos %= size;
    }

    printf("Survivor = %d\n", alive[0]);

    return 0;
}