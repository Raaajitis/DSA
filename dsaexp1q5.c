#include <stdio.h>
void multiplyMatrices(int *A, int*B , int*C , int r1, int c1, int c2){ 
    for(int i=0 ; i<r1 ;i++){
        for (int j=0 ;j<c2 ; j++){
            *(C + i * c2 + j) = 0 ; 
            for(int k=0 ; k<c1 ;k++)
            *(C + i * c2 + j)+=*(A + i * c1 + k) ** (B + k * c2 + j);
        }
    }
}
int main(){
    int r1,c1,r2,c2;
    printf("Enter the dimentions of matrix A: ");
    scanf("%d%d",&r1 ,&c1);
    printf("Enter the dimentions of matrix B: ");
    scanf("%d%d",&r2 ,&c2);

    if(c1 != r2){
        printf("Matrix multiplication is not possible");
        return 1;
    }
int A[r1][c1] , B[r2][c2], C[r1][c2];
printf("Enter the elements of matrix A: ");
for(int i=0; i<r1 ;i++)
for(int j=0; j<c1; j++)
scanf("%d", &A[i][j]);

printf("Enter elements of matrix B: ");
for (int i=0 ; i<r2 ; i++)
for (int j=0; j<c2 ; j++)
scanf("%d" , &B[i][j]);

multiplyMatrices((int*)A,(int*)B, (int*)C, r1, c1, c2);
printf("Resultant matrix: \n");
for(int i=0; i<r1 ; i++){
    for(int j=0; j<c2; j++)
    printf("%d" , C[i][j]);
    printf("\n");
}
return 0;
}