#include<stdio.h>

int parent[105];
int infected[105];

int main(){

    int n;

    scanf("%d",&n);

    parent[1]=0;

    for(int i=2;i<=n;i++)
        scanf("%d",&parent[i]);

    int cur=n;
    int time=0;
    int cnt=0;

    while(cur!=0){

        if(!infected[cur]){
            infected[cur]=1;
            cnt++;
        }

        cur=parent[cur];

        if(cur)
            time++;
    }

    printf("%d\n",time);
    printf("%d\n",cnt);

    return 0;
}