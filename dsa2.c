#include <stdio.h>
int main(){
    int a[]= {2.9,3.6,8,9.7,5.8};
    int j, *q = a;
    for(j=0;j<5;j++){
    printf("\t %d" , *q);
    ++q;
    }
    return 0;
}