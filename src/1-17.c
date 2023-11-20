/* Write a program to print all input lines that are longer than 80 characters.  */

#include <stdio.h>

#define MAX_LINE 1024
#define PERMITTED_LINE 80

int GetLine(char [], int);

int main()
{
    int len;
    char line[MAX_LINE] = {0};
    while ((len = GetLine(line, MAX_LINE)) != 0)
        if (len >= PERMITTED_LINE)
            printf("Line 80+ char: %s\n", line);
    return 0;
}

int GetLine(char line[], int max)
{
    char c;
    int ix = 0;
    while (ix < max - 1 && (c = getchar()) != '\n' && c != EOF)
    {
        line[ix] = c;
        ix++;
    }
    line[ix] = '\0';
    return ix;
}