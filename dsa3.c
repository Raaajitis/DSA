#include <stdio.h>
main(){
    char *q;
    q="Hello";
    printf("%c \n" , *& *q);
    return 0;
}