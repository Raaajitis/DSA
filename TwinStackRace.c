#include<stdio.h>

int main(){

    int A[10000],B[10000];

    int topA=-1,topB=-1;

    int x;

    scanf("%d",&x);

    A[++topA]=x;

    int pops=0,maxSize=1;

    while(topA!=-1 || topB!=-1){

        if(topA!=-1){

            int cur=A[topA--];

            pops++;

            if(cur>1){

                if(cur%2==0){

                    A[++topA]=cur/2;
                    B[++topB]=cur/2;

                }else{

                    B[++topB]=cur-1;
                }
            }
        }
        else{

            int cur=B[topB--];

            pops++;

            if(cur>1){

                if(cur%2==0){

                    A[++topA]=cur/2;
                    A[++topA]=cur/2;

                }else{

                    A[++topA]=cur-1;
                }
            }
        }

        int size=(topA+1)+(topB+1);

        if(size>maxSize)
            maxSize=size;
    }

    printf("Total Pops = %d\n",pops);
    printf("Maximum Size = %d\n",maxSize);

    return 0;
}