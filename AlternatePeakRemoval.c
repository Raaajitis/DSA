#include<stdio.h>

int main(){

    int a[100];
    int n;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int removed=0;
    int leftTurn=1;

    while(1){

        int idx=-1;

        if(leftTurn){

            for(int i=1;i<n-1;i++){

                if(a[i]>a[i-1] && a[i]>a[i+1]){
                    idx=i;
                    break;
                }
            }
        }
        else{

            for(int i=n-2;i>=1;i--){

                if(a[i]>a[i-1] && a[i]>a[i+1]){
                    idx=i;
                    break;
                }
            }
        }

        if(idx==-1)
            break;

        for(int i=idx;i<n-1;i++)
            a[i]=a[i+1];

        n--;
        removed++;
        leftTurn=!leftTurn;
    }

    printf("Removed = %d\n",removed);

    printf("Final Array:\n");

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}