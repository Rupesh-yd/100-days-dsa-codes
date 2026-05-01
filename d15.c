//Matrix Diagonal Sum
#include <stdio.h>
int main() {
    int m, n, sum = 0;
    int matrix[100][100];
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }
    printf("%d", sum);
    return 0;
}
