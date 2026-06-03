#include <stdio.h>

int main() {

    int credibility[] = {10,20,5,30,15};
    char person[] = {'A','B','C','D','E'};

    int n = 5;

    double sum = 0;

    int version = 1;

    printf("Version 1 created by A\n");

    sum += credibility[0];

    for(int i=1;i<n;i++) {

        double avg = sum / i;

        if(credibility[i] > avg) {

            version++;

            printf("Version %d created by %c\n",
                   version,
                   person[i]);
        }

        sum += credibility[i];
    }

    printf("\nTotal Versions = %d\n",
           version);

    return 0;
}