#include "libgeometry/geometry.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max_str = 1000, size_output_str;
    char* input_str = NULL;
    input_str = calloc(max_str, sizeof(char));
    char* output_str = NULL;

    fgets(input_str, max_str, stdin);
    size_output_str = correct_str(input_str);

    output_str = calloc(size_output_str, sizeof(char));
    str_copy(input_str, output_str);
    free(input_str);
    output(output_str);

    perimeter(output_str);
    area(output_str);
    return 0;
}