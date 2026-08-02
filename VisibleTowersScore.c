#include <stdio.h>

#define MAXN 1005

int main() {

    int n;
    scanf("%d",&n);

    int a[MAXN];

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int ans=0;

    for(int i=0;i<n;i++){

        for(int j=i+1;j<n;j++){

            if(a[j]>a[i])
                break;

            ans++;
        }
    }

    printf("%d\n",ans);

    return 0;
}