#include <stdio.h>

int main() {
    int n;
    int g[n];
    int sum = 0;

    
    printf("Enter n numbers of array:\n");
    scanf("%d" , &n);
    if(n<1){
        return 1;
    }
    
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &g[i]);
    }


    for (int i = 0; i < n; i++) {
      
        sum += g[i];
    }

    printf("The sum of the array elements is: %d\n", sum);

    return 0;
}