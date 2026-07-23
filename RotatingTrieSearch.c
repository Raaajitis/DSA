#include <stdio.h>
#include <string.h>

char words[200][55];

int main() {

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%s",words[i]);

    int q;
    scanf("%d",&q);

    while(q--){

        char s[55];
        scanf("%s",s);

        int len=strlen(s);
        int ans=0;

        char rot[55];

        for(int r=0;r<len;r++){

            int k=0;

            for(int i=r;i<len;i++)
                rot[k++]=s[i];

            for(int i=0;i<r;i++)
                rot[k++]=s[i];

            rot[k]='\0';

            for(int j=0;j<n;j++){

                if(strcmp(rot,words[j])==0){
                    ans++;
                    break;
                }
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}