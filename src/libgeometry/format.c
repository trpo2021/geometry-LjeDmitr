#include "geometry.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int skip_space(char input_str[], int i)
{
    while (input_str[i] == ' ') {
        i++;
    }
    return i;
}

int check_point(char input_str[], int i, int* k)
{
    int j = 0;
    if (input_str[i] == '-') {
        i++;
        k++;
    }
    if (isdigit(input_str[i]) == 0) {
        printf("Error at column %d '%c': expected '<double>'\n",
               i,
               input_str[i]);
        exit(0);
    }
    while ((isdigit(input_str[i]) > 0) || (input_str[i] == '.')) {
        if ((input_str[i] == '.') && (j == 0)) {
            j = i;
        }
        i++;
        k++;
        if ((input_str[i] == '.') && (j > 0)) {
            printf("Error at column %d '%c': expected '<double>'\n",
                   i,
                   input_str[i]);
            exit(0);
        }
    }
    if ((input_str[j] == '.') && (isdigit(input_str[j + 1]) == 0)) {
        printf("Error at column %d '%c': expected '<double>'\n",
               i,
               input_str[i]);
        exit(0);
    }
    return i;
}

int check_rad(char input_str[], int i, int* k)
{
    int j = 0;
    if (isdigit(input_str[i]) == 0) {
        printf("Error at column %d '%c': expected '<unsigned double>'\n",
               i,
               input_str[i]);
        exit(0);
    }
    while ((isdigit(input_str[i]) > 0) || (input_str[i] == '.')) {
        if ((input_str[i] == '.') && (j == 0)) {
            j = i;
        }
        i++;
        k++;
        if ((input_str[i] == '.') && (j > 0)) {
            printf("Error at column %d '%c': expected '<double>'\n",
                   i,
                   input_str[i]);
            exit(0);
        }
    }
    if ((input_str[j] == '.') && (isdigit(input_str[j + 1]) == 0)) {
        printf("Error at column %d '%c': expected '<double>'\n",
               i,
               input_str[i]);
        exit(0);
    }
    return i;
}

int correct_str(char input_str[])
{
    char check_str[] = {'c', 'i', 'r', 'c', 'l', 'e'};
    int i = 0, k = 0, g = 0;
    i = skip_space(input_str, i);
    for (; (input_str[i] != '(') && (isalpha(input_str[i]) > 0);
         i++, k++, g++) {
        if (check_str[g] != (tolower(input_str[i]))) {
            printf("Error at column %d '%c': expected 'circle'\n",
                   i,
                   input_str[i]);
            exit(0);
        }
    }
    i = skip_space(input_str, i);
    if (input_str[i] != '(') {
        printf("Error at column %d '%c': expected '('\n", i, input_str[i]);
        exit(0);
    } else {
        i++;
        k++;
    }
    i = skip_space(input_str, i);
    i = check_point(input_str, i, &k);
    k++;
    i = skip_space(input_str, i);
    i = check_point(input_str, i, &k);
    i = skip_space(input_str, i);
    if (input_str[i] != ',') {
        printf("Error at column %d '%c': expected ','\n", i, input_str[i]);
        exit(0);
    } else {
        i++;
        k++;
    }
    k++;
    i = skip_space(input_str, i);
    i = check_rad(input_str, i, &k);
    i = skip_space(input_str, i);
    if (input_str[i] != ')') {
        printf("Error at column %d '%c': expected ')'\n", i, input_str[i]);
        exit(0);
    } else {
        i++;
        k++;
    }
    i = skip_space(input_str, i);
    if (input_str[i] != '\n') {
        printf("Error at column %d '%c': unexpected token\n", i, input_str[i]);
        exit(0);
    }
    printf("Input is correct\n(case insensitive and ignoring whitespace)\n");
    return k;
}

void str_copy(char input_str[], char* output_str)
{
    int i = 0, j;
    i = skip_space(input_str, i);
    for (j = 0; (input_str[i] != '(') && (input_str[i] != ' '); i++, j++) {
        output_str[j] = input_str[i];
    }
    output_str[j] = '(';
    j++;
    while ((input_str[i] != '-') && (isdigit(input_str[i]) == 0)) {
        i++;
    }
    for (; input_str[i] != ' '; i++, j++) {
        output_str[j] = input_str[i];
    }
    output_str[j] = ' ';
    j++;
    i = skip_space(input_str, i);
    for (; (input_str[i] != ',') && (input_str[i] != ' '); i++, j++) {
        output_str[j] = input_str[i];
    }
    output_str[j] = ',';
    j++;
    output_str[j] = ' ';
    j++;
    i = skip_space(input_str, i);
    if (input_str[i] == ',') {
        i++;
    }
    i = skip_space(input_str, i);
    for (; (input_str[i] != ')') && (input_str[i] != ' '); i++, j++) {
        output_str[j] = input_str[i];
    }
    output_str[j] = ')';
    j++;
    output_str[j] = '\0';
}
void output(char* output_str)
{
    fputs(output_str, stdout);
    printf("\n");
}