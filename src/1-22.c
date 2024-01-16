/* Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column */

/* 01234567890123456789012345678901 // length = 32 */

#include <stdio.h>

#define INIT 0
#define MAX_LINE 1024
#define LINE_BOUND 16
#define TAB 8
#define CH_TAB '\t'
#define CH_BLANK ' '
#define CH_NEW_LINE '\n'

char line[MAX_LINE] = {INIT}, new_line[MAX_LINE * TAB + 32] = {INIT};

int GetLine(int);
void Fold(void);
void PrintLine(char []);

int main()
{
    extern char line[], new_line[];
    int len = INIT;
    while ((len = GetLine(MAX_LINE)) != 0)
    {
        PrintLine(line);
        Fold();
        PrintLine(new_line);
    }
    return 0;
}

int GetLine(int max)
{
    extern char line[];
    int ix = INIT;
    char c;
    for (; ix < max - 1 && (c = getchar()) != EOF && c != '\n'; ix++)
        line[ix] = c;
    line[ix] = '\0';
    return ix;
}
void Fold()
{
    int i = 0;
    int j = 0;
    int last_blank = 0;
    int boundary = 0;
    while (line[i] != '\0')
    {
        /* Finding last blank ch */
        for (; boundary < LINE_BOUND && line[i] != '\0'; boundary++, i++)
        {
            if (line[i] == ' ' || line[i] == '\t')
            {
                last_blank = i ;
            }
        }   

        /* Copying */
        for (; j < i; j++)
        {

        }
    }
    new_line[j] = '\0';
    return;
}
void PrintLine(char line[])
{
    int ix = INIT;
    for (; line[ix] != '\0'; ix++)
    {
        putchar(line[ix]);
        if (line[ix] == '\n')
        {
            putchar('|');
        }
    }
    return;
}

