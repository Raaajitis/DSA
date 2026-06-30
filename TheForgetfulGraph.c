#include <stdio.h>

int main(){

    int parent=-1;
    int lastParent=-1;

    int edges=4;

    int path[]={1,3,2,3};

    for(int i=1;i<4;i++){

        parent=path[i-1];

        if(path[i]==3){

            if(lastParent!=-1 &&
               lastParent!=parent){

                edges=1;
            }

            lastParent=parent;
        }
    }

    printf("Edges remaining = %d\n",edges);

    return 0;
}