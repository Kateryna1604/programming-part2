#include "lib.h"

#include <stdio.h>

void read_matrix(
    const char *filename,
    int matrix[MAX_ROWS][MAX_COLS],
    int *rows,
    int *cols)
    
{

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        return;
    }

    fscanf(file, "%d %d", rows, cols);

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {

            fscanf(
                file,
                "%d",
                (*(matrix + i) + j));
        }
    }

    fclose(file);
}

int find_max(
    int matrix[MAX_ROWS][MAX_COLS],
    int rows,
    int cols)
{
    int max = *(*(matrix));

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            if (*(*(matrix + i) + j) > max) {

                max = *(*(matrix + i) + j);
            }
        }
    }

    return max;
} 
int find_sum(
    int matrix [MAX_ROWS][MAX_COLS],
    int rows,
    int cols)
 {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += *(*(matrix + i) + j);
        }
    }
    printf("Sum element: %d\n", sum);
 
    return sum;
 }

void write_result(
    const char *filename,
    int max)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        return;
    }

    fprintf(
        file,
        "Maximum element: %d\n",
        max);

    fclose(file);
}
