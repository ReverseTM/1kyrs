#include <stdio.h>
#include <stdlib.h>

long long **get_memory_matrix(long long **matrix, int size_matrix)
{
    matrix = (long long **)malloc(size_matrix * sizeof(long long *));

    for (int i = 0; i < size_matrix; i++) {
        matrix[i] = (long long *)malloc(size_matrix * sizeof(long long));
    }

    return matrix;
}

void scan_matrix(long long **matrix, int size_matrix)
{
    for (int i = 0; i < size_matrix; i++) {
        for (int j = 0; j < size_matrix; j++) {
            scanf("%lld", &matrix[i][j]);
        }
    }
}

int main(void)
{
    long long **matrix = NULL;

    int size_matrix = 0;
    int num_test = 0;
    int max_size = 0;

    scanf("%d %d", &num_test, &max_size);

    for (int g = 0; g < num_test; g++) {
        scanf("%d", &size_matrix);
        matrix = get_memory_matrix(matrix, size_matrix);
        scan_matrix(matrix, size_matrix);
        
        long long min = 9223372036854775807;
        long long max = -9223372036854775807;
        long long nmax = 0;
        long long nmin = 0;

        for (int i = 0; i < size_matrix; i++) {
            long long multuplication = 1;
            
            for (int j = 0; j < size_matrix; j++) {
                multuplication = multuplication * matrix[i][j];
            }
            if (multuplication >= max) {
                max = multuplication;
                nmax = i;
            }
            if (multuplication <= min) {
                min = multuplication;
                nmin = i;
            }
        }
        for (int k = 0; k < size_matrix; k++) {
            for (int j = 0; j < size_matrix; j++) {
                if (k == nmax) {
                    printf("%lld ", matrix[nmin][j]);
                } else if (k == nmin) {
                    printf("%lld ", matrix[nmax][j]);
                } else {
                    printf("%lld ", matrix[k][j]);
                }
            }
            printf("\n");
        }
    }
    free(matrix);
    return 0;
}

