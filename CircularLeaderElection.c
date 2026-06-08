#include <stdio.h>

int main() {

    int strength[] = {2,3,1,2,4};

    int n = sizeof(strength)/sizeof(strength[0]);

    int visited[100] = {0};

    int current = 0;
    int leader = 0;

    while(!visited[current]) {

        visited[current] = 1;

        leader = current;

        current =
            (current + strength[current]) % n;
    }

    printf("Leader Index = %d\n",
           leader);

    return 0;
}