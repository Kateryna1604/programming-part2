#include "lib.h"
#include <stdio.h>


void process_file(const char *input_path, const char *output_path)
{
    FILE *input = fopen(input_path, "r");

    if (input == NULL) {
        return;
    }

    int number = 0;
    int min = 0;
    int max = 0;
    int sum = 0;
    int count = 0;
    int even_count = 0;

    fscanf(input, "%d", &number);

    min = number;
    max = number;

    do {
        if (number < min) {
            min = number;
        }

        if (number > max) {
            max = number;
        }

        if (number % 2 == 0) {
            even_count++;
        }

        sum += number;
        count++;

    } while (fscanf(input, "%d", &number) == 1);

    fclose(input);

    float average = (float)sum / count;

    FILE *output = fopen(output_path, "w");

    if (output == NULL) {
        return;
    }

    fprintf(output, "Minimum: %d\n", min);
    fprintf(output, "Maximum: %d\n", max);
    fprintf(output, "Average: %.2f\n", average);
    fprintf(output, "Even numbers: %d\n", even_count);

    fclose(output);
}
