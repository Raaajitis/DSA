#include <stdio.h>

#define MAXN 1005

int main() {

    int n;
    scanf("%d",&n);

    int a[MAXN];

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int best=0;

    for(int i=1;i<n-1;i++){

        if(a[i]>a[i-1] && a[i]>a[i+1]){

            int len=1;
            int cur=i;

            while(1){

                int next=-1;

                for(int j=cur-1;j>=0;j--){

                    if(a[j]>a[cur]){
                        next=j;
                        break;
                    }
                }

                if(next==-1)
                    break;

                len++;
                cur=next;
            }

            if(len>best)
                best=len;
        }
    }

    printf("%d\n",best);

    return 0;
}