#include <stdio.h>
int main(){
    int rows, cols;
    printf("Enter rows and columns: ");
    scanf("%d%d" , &rows , &cols);
    int matrix[rows][cols];
    printf("Enter elements of the matrix: \n");
    for(int i=0; i<rows ; i++)
    for(int j=0; j<cols ; j++)
    scanf("%d" , &matrix[i][j]);
    printf("Row sum:\n");
    for(int i=0; i<rows ;i++){
        int rowsum=0;
        for(int j=0;j<cols;j++)
        rowsum+=matrix[i][j];
        printf("Row %d : %d \n" , i+1,rowsum);
    }
    printf("Column sum: \n");
    for(int j=0 ; j<cols ; j++){
        int colsum=0;
        for(int i=0; i<rows ; i++)
        colsum+= matrix [i][j];
        printf("Column %d : %d \n" , j+1 , colsum);
    }
return 0;
    }
