#include <stdio.h>

int main() {

    int n;
    scanf("%d",&n);

    int a[100];

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int locked[100]={0};
    int score=0;

    while(1){

        int done=1;

        for(int i=0;i<n;i++)
            if(!locked[i]) done=0;

        if(done) break;

        int best=-1;

        for(int i=0;i<n;i++){

            if(locked[i]) continue;

            if(best==-1 || a[i]<a[best])
                best=i;
        }

        score+=a[best];
        locked[best]=1;

        for(int j=best+1;j<n;j++)
            if(!locked[j] && a[j]<a[best])
                locked[j]=1;
    }

    printf("%d\n",score);

    return 0;
}