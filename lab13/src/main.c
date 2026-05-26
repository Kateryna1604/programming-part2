#include "lib.h"

/**
 * @brief Main function.
 */

int main()
{
    int matrix[MAX_ROWS][MAX_COLS];

    int rows = 0;
    int cols = 0;

    read_matrix(
        "assets/input.txt",
        matrix,
        &rows,
        &cols);

    int max = find_max(
        matrix,
        rows,
        cols);

    write_result(
        "assets/output.txt",
        max);

    return 0;
}
