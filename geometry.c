#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int correct(char str[], int MAX)
{
    char check_str[] = {'c', 'i', 'r', 'c', 'l', 'e'};
    int i = 0, j = 0, k = 0, g = 0;
    while (str[i] == ' ') {
        i++;
    }
    for (; (str[i] != '(') && (isalpha(str[i]) > 0); i++, k++, g++) {
        if (check_str[g] != (tolower(str[i]))) {
            printf("Error at column %d '%c': expected 'circle'\n", i, str[i]);
            exit(0);
        }
    }
    while (str[i] == ' ') {
        i++;
    }
    if (str[i] != '(') {
        printf("Error at column %d '%c': expected '('\n", i, str[i]);
        exit(0);
    } else {
        i++;
        k++;
    }
    while ((isdigit(str[i]) == 0) && (str[i] != '-')) {
        if (str[i] == ' ') {
            i++;
        } else {
            printf("Error at column %d '%c': expected '<double>'\n", i, str[i]);
            exit(0);
        }
    }
    if (str[i] == '-') {
        i++;
        k++;
    }
    if (isdigit(str[i]) == 0) {
        printf("Error at column %d '%c': expected '<double>'\n", i, str[i]);
        exit(0);
    }
    while ((isdigit(str[i]) > 0) || (str[i] == '.')) {
        if ((str[i] == '.') && (j == 0)) {
            j++;
        }
        i++;
        k++;
        if ((str[i] == '.') && (j > 0)) {
            printf("Error at column %d '%c': expected '<double>'\n", i, str[i]);
            exit(0);
        }
    }
    k++;
    while ((isdigit(str[i]) == 0) && (str[i] != '-')) {
        if (str[i] == ' ') {
            i++;
        } else {
            printf("Error at column %d '%c'", i, str[i]);
            printf(": expected '<double>' or 'space'\n");
            exit(0);
        }
    }
    if (str[i] == '-') {
        i++;
        k++;
    }

    if (isdigit(str[i]) == 0) {
        printf("Error at column %d '%c': expected '<double>'\n", i, str[i]);
        exit(0);
    }
    j = 0;
    while ((isdigit(str[i]) > 0) || (str[i] == '.')) {
        if ((str[i] == '.') && (j == 0)) {
            j = i;
        }
        i++;
        k++;
        if ((str[i] == '.') && (j > 0)) {
            printf("Error at column %d '%c': expected '<double>'\n", i, str[i]);
            exit(0);
        }
    }
    if ((str[j] == '.') && (isdigit(str[j + 1]) == 0)) {
        printf("Error at column %d '%c': expected '<double>'\n", i, str[i]);
        exit(0);
    }
    while (str[i] == ' ') {
        i++;
    }
    if (str[i] != ',') {
        printf("Error at column %d '%c': expected ','\n", i, str[i]);
        exit(0);
    } else {
        i++;
        k++;
    }
    k++;
    while (isdigit(str[i]) == 0) {
        if (str[i] == ' ') {
            i++;
        } else {
            printf("Error at column %d '%c'", i, str[i]);
            printf(": expected '<double>' or 'space'\n");
            exit(0);
        }
    }
    j = 0;
    while ((isdigit(str[i]) > 0) || (str[i] == '.')) {
        if ((str[i] == '.') && (j == 0)) {
            j = i;
        }
        i++;
        k++;
        if ((str[i] == '.') && (j > 0)) {
            printf("Error at column %d '%c': expected '<double>'\n", i, str[i]);
            exit(0);
        }
    }
    if ((str[j] == '.') && (isdigit(str[j + 1]) == 0)) {
        printf("Error at column %d '%c': expected '<double>'\n", i, str[i]);
        exit(0);
    }
    while (str[i] == ' ') {
        i++;
    }
    if (str[i] != ')') {
        printf("Error at column %d '%c': expected ')'\n", i, str[i]);
        exit(0);
    } else {
        i++;
        k++;
    }
    while (str[i] == ' ') {
        i++;
    }
    if (str[i] != '\n') {
        printf("Error at column %d '%c': unexpected token\n", i, str[i]);
        exit(0);
    }
    return k;
}

void str_copy(char str[], char* str_1, int MAX)
{
    int i = 0, j;
    while (str[i] == ' ') {
        i++;
    }
    for (j = 0; (str[i] != '(') && (str[i] != ' '); i++, j++) {
        str_1[j] = str[i];
    }
    str_1[j] = '(';
    j++;
    while ((str[i] != '-') && (isdigit(str[i]) == 0)) {
        i++;
    }
    for (; str[i] != ' '; i++, j++) {
        str_1[j] = str[i];
    }
    str_1[j] = ' ';
    j++;
    while (str[i] == ' ') {
        i++;
    }
    for (; (str[i] != ',') && (str[i] != ' '); i++, j++) {
        str_1[j] = str[i];
    }
    str_1[j] = ',';
    j++;
    str_1[j] = ' ';
    j++;
    while (str[i] == ' ') {
        i++;
    }
    if (str[i] == ',') {
        i++;
    }
    while (str[i] == ' ') {
        i++;
    }
    for (; (str[i] != ')') && (str[i] != ' '); i++, j++) {
        str_1[j] = str[i];
    }
    str_1[j] = ')';
}

void output(char* str)
{
    fputs(str, stdout);
}

int main()
{
    int MAX = 1000, size;
    char* str = NULL;
    str = calloc(MAX, sizeof(char));
    char* str_1 = NULL;
    fgets(str, MAX, stdin);
    size = correct(str, MAX);
    str_1 = calloc(size, sizeof(char));
    str_copy(str, str_1, MAX);
    output(str_1);
    free(str);
    printf("\n");
    return 0;
}