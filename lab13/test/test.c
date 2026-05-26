#include <assert.h>

#include "../src/lib.h"

int main()
{
    int matrix[MAX_ROWS][MAX_COLS] = {
        {1, 2},
        {10, 4}
    };

    int result = find_max(
        matrix,
        2,
        2);

    assert(result == 10);

    return 0;
}
