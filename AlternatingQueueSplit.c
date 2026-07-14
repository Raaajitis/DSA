#include<stdio.h>

int main(){

    int q[10000];

    int front=0,rear=0;

    int x;

    scanf("%d",&x);

    q[rear++]=x;

    int pops=0;
    int mx=1;

    while(front<rear){

        int cur=q[front++];

        pops++;

        if(cur>=3 && cur%3==0){

            q[rear++]=cur/3;
            q[rear++]=(2*cur)/3;
        }

        int size=rear-front;

        if(size>mx)
            mx=size;
    }

    printf("Total Pops = %d\n",pops);
    printf("Maximum Queue Size = %d\n",mx);

    return 0;
}