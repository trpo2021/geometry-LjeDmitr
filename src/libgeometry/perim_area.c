#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "geometry.h"

void perimeter(char* output_str)
{
    int i = 0, rad;
    float p;

    while (output_str[i] != ',') {
        i++;
    }
    i += 2;

    rad = atoi(&output_str[i]);
    p = 2 * M_PI * rad;
    printf("perimeter = %.3f\n", p);
}

void area(char* output_str)
{
    int i = 0, rad;
    float s;

    while (output_str[i] != ',') {
        i++;
    }
    i += 2;

    rad = atoi(&output_str[i]);
    s = M_PI * rad * rad;
    printf("area = %.3f\n", s);
}