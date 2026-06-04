#include <stdio.h>

typedef struct {
    char id;
    int priority;
} Task;

int main() {

    Task tasks[] = {
        {'A',10},
        {'B',3},
        {'C',7}
    };

    int n = 3;

    printf("Execution Order:\n");

    while(n > 0) {

        int best = 0;

        for(int i=1;i<n;i++) {

            if(tasks[i].priority >
               tasks[best].priority)
                best = i;
        }

        printf("%c ", tasks[best].id);

        for(int i=0;i<n;i++) {

            if(i != best)
                tasks[i].priority++;
        }

        for(int i=best;i<n-1;i++)
            tasks[i] = tasks[i+1];

        n--;
    }

    return 0;
}