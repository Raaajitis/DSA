#include<stdio.h>

int main(){

    int stack[10000];
    int top=-1;

    int x;

    scanf("%d",&x);

    stack[++top]=x;

    int pops=0;
    int maxSize=1;

    while(top!=-1){

        int cur=stack[top--];

        pops++;

        if(cur>1){

            int a=cur/2;
            int b=cur-a;

            stack[++top]=a;
            stack[++top]=b;
        }

        if(top+1>maxSize)
            maxSize=top+1;
    }

    printf("Total Pops = %d\n",pops);
    printf("Maximum Stack Size = %d\n",maxSize);

    return 0;
}