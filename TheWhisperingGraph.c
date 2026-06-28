#include <stdio.h>

int main() {

    int AB = 5;
    int BC = 3;

    char path[] = {'A','B','A'};

    for(int i=0;i<3;i++){

        if(path[i]=='A'){

            AB++;

            if(BC>1)
                BC--;
        }
        else{

            BC++;

            if(AB>1)
                AB--;
        }
    }

    printf("AB = %d\n",AB);
    printf("BC = %d\n",BC);

    return 0;
}