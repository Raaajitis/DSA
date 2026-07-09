#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);

    int a[100],power[100];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        power[i]=1;
    }

    for(int i=1;i<n;i++){

        if(a[i]>a[i-1])
            power[i]=power[i-1]+1;
    }

    for(int i=n-2;i>=0;i--){

        if(a[i]>a[i+1] && power[i]<power[i+1]+1)
            power[i]=power[i+1]+1;
    }

    int mx=0,sum=0;

    for(int i=0;i<n;i++){

        if(power[i]>mx)
            mx=power[i];

        sum+=power[i];
    }

    printf("Maximum Power = %d\n",mx);
    printf("Sum = %d\n",sum);

    return 0;
}