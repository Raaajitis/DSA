#include <stdio.h>
int main(){

    int a;

    printf("Enter the year: ");
    scanf("%d" , &a);

    if(a%400==0 & a%100==0){ printf("It is a leap year");}
    if(a%4==0){ printf("It is a leap year");}
    else{ printf( "It is not a leap year");}

    return 0;


}