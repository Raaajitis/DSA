#include <stdio.h>

int main() {

    int n;
    scanf("%d",&n);

    int a[1005];

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int score=0;

    while(1){

        int peak=-1;

        for(int i=1;i<n-1;i++){

            if(a[i]>a[i-1] && a[i]>a[i+1]){
                peak=i;
                break;
            }
        }

        if(peak==-1)
            break;

        score+=a[peak];

        for(int i=peak;i<n-1;i++)
            a[i]=a[i+1];

        n--;
    }

    printf("%d\n",score);

    return 0;
}