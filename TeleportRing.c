#include <stdio.h>

int main(){

    int n;

    scanf("%d",&n);

    int a[100];
    int visit[100]={0};

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int idx=0;
    int moves=0;
    int sum=0;

    while(visit[idx]<2){

        visit[idx]++;

        sum+=a[idx];

        int jump=a[idx];

        a[idx]=1;

        idx=(idx+jump)%n;

        moves++;
    }

    printf("Moves = %d\n",moves);
    printf("Sum = %d\n",sum);

    return 0;
}