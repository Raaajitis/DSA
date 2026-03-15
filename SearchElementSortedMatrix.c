#include <stdio.h>

int searchMatrix(int matrix[3][3], int target) {

    int row = 0;
    int col = 2;

    while (row < 3 && col >= 0) {

        if (matrix[row][col] == target)
            return 1;

        else if (matrix[row][col] > target)
            col--;

        else
            row++;
    }

    return 0;
}

int main() {

    int matrix[3][3] = {
        {1,4,7},
        {2,5,8},
        {3,6,9}
    };

    int target = 5;

    if (searchMatrix(matrix,target))
        printf("Element Found\n");
    else
        printf("Element Not Found\n");

    return 0;
}