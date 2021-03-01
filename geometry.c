#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int correct(char input_str[])
{
    char check_str[] = {'c', 'i', 'r', 'c', 'l', 'e'};
    int i = 0, j = 0, k = 0, g = 0;
    while (input_str[i] == ' ') {
        i++;
    }
    for (; (input_str[i] != '(') && (isalpha(input_str[i]) > 0); i++, k++, g++) {
        if (check_str[g] != (tolower(input_str[i]))) {
            printf("Error at column %d '%c': expected 'circle'\n", i, input_str[i]);
            exit(0);
        }
    }
    while (input_str[i] == ' ') {
        i++;
    }
    if (input_str[i] != '(') {
        printf("Error at column %d '%c': expected '('\n", i, input_str[i]);
        exit(0);
    } else {
        i++;
        k++;
    }
    while ((isdigit(input_str[i]) == 0) && (input_str[i] != '-')) {
        if (input_str[i] == ' ') {
            i++;
        } else {
            printf("Error at column %d '%c': expected '<double>'\n", i, input_str[i]);
            exit(0);
        }
    }
    if (input_str[i] == '-') {
        i++;
        k++;
    }
    if (isdigit(input_str[i]) == 0) {
        printf("Error at column %d '%c': expected '<double>'\n", i, input_str[i]);
        exit(0);
    }
    while ((isdigit(input_str[i]) > 0) || (input_str[i] == '.')) {
        if ((input_str[i] == '.') && (j == 0)) {
            j++;
        }
        i++;
        k++;
        if ((input_str[i] == '.') && (j > 0)) {
            printf("Error at column %d '%c': expected '<double>'\n", i, input_str[i]);
            exit(0);
        }
    }
    k++;
    while ((isdigit(input_str[i]) == 0) && (input_str[i] != '-')) {
        if (input_str[i] == ' ') {
            i++;
        } else {
            printf("Error at column %d '%c'", i, input_str[i]);
            printf(": expected '<double>' or 'space'\n");
            exit(0);
        }
    }
    if (input_str[i] == '-') {
        i++;
        k++;
    }

    if (isdigit(input_str[i]) == 0) {
        printf("Error at column %d '%c': expected '<double>'\n", i, input_str[i]);
        exit(0);
    }
    j = 0;
    while ((isdigit(input_str[i]) > 0) || (input_str[i] == '.')) {
        if ((input_str[i] == '.') && (j == 0)) {
            j = i;
        }
        i++;
        k++;
        if ((input_str[i] == '.') && (j > 0)) {
            printf("Error at column %d '%c': expected '<double>'\n", i, input_str[i]);
            exit(0);
        }
    }
    if ((input_str[j] == '.') && (isdigit(input_str[j + 1]) == 0)) {
        printf("Error at column %d '%c': expected '<double>'\n", i, input_str[i]);
        exit(0);
    }
    while (input_str[i] == ' ') {
        i++;
    }
    if (input_str[i] != ',') {
        printf("Error at column %d '%c': expected ','\n", i, input_str[i]);
        exit(0);
    } else {
        i++;
        k++;
    }
    k++;
    while (isdigit(input_str[i]) == 0) {
        if (input_str[i] == ' ') {
            i++;
        } else {
            printf("Error at column %d '%c'", i, input_str[i]);
            printf(": expected '<double>' or 'space'\n");
            exit(0);
        }
    }
    j = 0;
    while ((isdigit(input_str[i]) > 0) || (input_str[i] == '.')) {
        if ((input_str[i] == '.') && (j == 0)) {
            j = i;
        }
        i++;
        k++;
        if ((input_str[i] == '.') && (j > 0)) {
            printf("Error at column %d '%c': expected '<double>'\n", i, input_str[i]);
            exit(0);
        }
    }
    if ((input_str[j] == '.') && (isdigit(input_str[j + 1]) == 0)) {
        printf("Error at column %d '%c': expected '<double>'\n", i, input_str[i]);
        exit(0);
    }
    while (input_str[i] == ' ') {
        i++;
    }
    if (input_str[i] != ')') {
        printf("Error at column %d '%c': expected ')'\n", i, input_str[i]);
        exit(0);
    } else {
        i++;
        k++;
    }
    while (input_str[i] == ' ') {
        i++;
    }
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
    while (input_str[i] == ' ') {
        i++;
    }
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
    while (input_str[i] == ' ') {
        i++;
    }
    for (; (input_str[i] != ',') && (input_str[i] != ' '); i++, j++) {
        output_str[j] = input_str[i];
    }
    output_str[j] = ',';
    j++;
    output_str[j] = ' ';
    j++;
    while (input_str[i] == ' ') {
        i++;
    }
    if (input_str[i] == ',') {
        i++;
    }
    while (input_str[i] == ' ') {
        i++;
    }
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
}

int main()
{
    int max_str = 1000, size_output_str;
    char* input_str = NULL;
    input_str = calloc(max_str, sizeof(char));
    char* output_str = NULL;
    fgets(input_str, max_str, stdin);
    size_output_str = correct(input_str);
    output_str = calloc(size_output_str, sizeof(char));
    str_copy(input_str, output_str);
    output(output_str);
    free(input_str);
    printf("\n");
    return 0;
}