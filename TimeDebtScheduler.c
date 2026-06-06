#include <stdio.h>

typedef struct {

    char name;
    int duration;
    int deadline;

} Task;

int main() {

    Task t[] = {

        {'A',10,6},
        {'B',4,20},
        {'C',5,25}

    };

    int n = 3;

    int currentTime = 0;
    int debt = 0;

    for(int i = 0; i < n; i++) {

        currentTime += t[i].duration;

        int effectiveDeadline =
            t[i].deadline - debt;

        int delay = 0;

        if(currentTime > effectiveDeadline)
            delay = currentTime -
                    effectiveDeadline;

        debt += delay;

        printf(
            "%c -> Delay=%d Debt=%d\n",
            t[i].name,
            delay,
            debt
        );
    }

    printf("\nFinal Debt = %d\n",
           debt);

    return 0;
}