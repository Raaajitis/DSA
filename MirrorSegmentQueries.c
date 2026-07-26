#include <stdio.h>

#define MAXN 1005

int a[MAXN];

void reverse(int l,int r){

    while(l<r){

        int temp=a[l];
        a[l]=a[r];
        a[r]=temp;

        l++;
        r--;
    }
}

int main(){

    int n,q;

    scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    while(q--){

        int type,l,r;

        scanf("%d%d%d",&type,&l,&r);

        if(type==1){

            reverse(l,r);

        }else{

            int ok=1;

            while(l<r){

                if(a[l]!=a[r]){
                    ok=0;
                    break;
                }

                l++;
                r--;
            }

            if(ok)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}