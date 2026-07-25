#include <stdio.h>
#include <stdlib.h>

#define MAXN 1005

int a[MAXN];

int cmp(const void *x, const void *y){
    return (*(int*)x)-(*(int*)y);
}

int main(){

    int n,q;

    scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    while(q--){

        int type;
        scanf("%d",&type);

        if(type==1){

            int idx,val;
            scanf("%d%d",&idx,&val);

            a[idx]=val;
        }

        else{

            int l,r;
            scanf("%d%d",&l,&r);

            int temp[MAXN];
            int m=0;

            for(int i=l;i<=r;i++)
                temp[m++]=a[i];

            qsort(temp,m,sizeof(int),cmp);

            int used[MAXN]={0};

            int mid=(m-1)/2;

            int left=mid-1;
            int right=mid+1;

            int order[MAXN];
            int k=0;

            order[k++]=temp[mid];

            while(left>=0 || right<m){

                if(left>=0)
                    order[k++]=temp[left--];

                if(right<m)
                    order[k++]=temp[right++];
            }

            int sum=0;

            for(int i=0;i<k;i+=2)
                sum+=order[i];

            printf("%d\n",sum);
        }
    }

    return 0;
}