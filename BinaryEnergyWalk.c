#include<stdio.h>

int main(){

    int n;

    scanf("%d",&n);

    int a[100];
    int vis[100]={0};

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int idx=0;
    int energy=a[0];
    int visited=0;

    while(idx>=0 && idx<n){

        if(vis[idx] || energy<=0)
            break;

        vis[idx]=1;
        visited++;

        if(a[idx]%2==0)
            idx++;
        else
            idx--;

        energy--;

        if(idx>=0 && idx<n)
            energy+=a[idx];
    }

    printf("Visited = %d\n",visited);
    printf("Energy = %d\n",energy);

    return 0;
}