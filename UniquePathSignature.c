#include <stdio.h>

#define MAXN 1005

int parent[MAXN];
char ch[MAXN];

int main(){

    int n,q;

    scanf("%d%d",&n,&q);

    scanf(" %c",&ch[1]);

    parent[1]=0;

    for(int i=2;i<=n;i++){
        scanf("%d %c",&parent[i],&ch[i]);
    }

    while(q--){

        int freq[26]={0};

        int u;
        scanf("%d",&u);

        while(u){

            freq[ch[u]-'a']++;
            u=parent[u];
        }

        int ok=1;

        for(int i=0;i<26;i++){

            if(freq[i]>1){

                ok=0;
                break;
            }
        }

        if(ok)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}