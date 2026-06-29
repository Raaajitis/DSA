#include <stdio.h>

int main(){

    int q[100]={8,5};

    int front=0,rear=2;

    int K=5;

    while(K-- && front<rear){

        int x=q[front++];

        if(x>0){

            int shadow=x/2;

            if(shadow){

                front--;

                for(int i=rear;i>front;i--)
                    q[i]=q[i-1];

                q[front]=shadow;
                rear++;
            }
        }
    }

    printf("Queue:\n");

    while(front<rear)
        printf("%d ",q[front++]);

    return 0;
}