// Matrix Addition
#include <stdio.h>

int main() {
    int m, n;
    int mat1[100][100], mat2[100][100], result[100][100];
    
    printf("Enter number of rows and columns:\n");
    scanf("%d %d", &m, &n);
    
    // Read first matrix
    printf("Enter elements of first %d x %d matrix:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    
    // Read second matrix
    printf("Enter elements of second %d x %d matrix:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    
    // Add matrices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    
    // Print result
    printf("Result matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", result[i][j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
