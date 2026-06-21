#ifndef LIB_H
#define LIB_H

#define MAX_ROWS 10
#define MAX_COLS 10

void read_matrix(
    const char *filename,
    int matrix[MAX_ROWS][MAX_COLS],
    int *rows,
    int *cols);

int find_max(
    int matrix[MAX_ROWS][MAX_COLS],
    int rows,
    int cols);

int find_sum(
    int matrix [MAX_ROWS][MAX_COLS],
    int rows,
    int cols);

void write_result(
    const char *filename,
    int max);

#endif
