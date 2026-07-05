#include <stdio.h>
#include <string.h>

#define MAX 1000

int reverseNum(int x){

    int rev=0;

    while(x){

        rev=rev*10+x%10;
        x/=10;
    }

    return rev;
}

int main(){

    int q[MAX];

    int front=0,rear=0;

    int k;

    scanf("%d",&k);

    while(k--){

        char op[10];

        scanf("%s",op);

        if(strcmp(op,"PUSH")==0){

            int x;

            scanf("%d",&x);

            q[rear++]=x;
        }
        else{

            if(front==rear)
                continue;

            int x=q[front++];

            if(x%3==0)
                q[rear++]=reverseNum(x);
        }
    }

    while(front<rear)
        printf("%d ",q[front++]);

    return 0;
}