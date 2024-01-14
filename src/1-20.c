/* Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter? */

#include <stdio.h>

#define INIT 0
#define TAB 8
#define MAX_LINE 1024
#define CH_TAB '\t'
#define CH_BLANK ' '

int len = INIT;
char line[MAX_LINE], new_line[(MAX_LINE) * TAB + 1];

int GetLine(char [], int);
void Detab(void);
void PrintLine(char arg[], char print_line[]);

int main()
{
    extern int len;
    extern char line[], new_line[];
    while ((len = GetLine(line, MAX_LINE)))
    {
        PrintLine("Original line: ", line);
        Detab();
        PrintLine("Detabed line: ", new_line);
    }
    return 0;
}

int GetLine(char line[], int max)
{
    int ix;
    char c;
    for (ix = INIT; ix < max - 1 && (c = getchar()) != '\n' && c != EOF; ix++)
        line[ix] = c;
    line[ix] = '\0';
    return ix;
}
void Detab(void)
{
    extern char line[], new_line[];
    int line_ix, new_line_ix = line_ix = INIT;
    int boundary = TAB;
    while (line[line_ix] != '\0')
    {
        if (line[line_ix] == CH_TAB)
        {
            /* Define an actual boundary */
            while (boundary <= new_line_ix)
                boundary = boundary + TAB;

            for (; new_line_ix != boundary; new_line_ix++)
                new_line[new_line_ix] = CH_BLANK;
        }
        else
        {
            new_line[new_line_ix] = line[line_ix];
            new_line_ix++;
        }
        line_ix++;
    }
    new_line[new_line_ix] = '\0';
    return;
}
void PrintLine(char arg[], char print_line[])
{ 
    printf("%s", arg);
    int ix = INIT;
    int boundary = TAB;
    char c;
    while (print_line[ix] != '\0')
    {
        if (print_line[ix] == CH_TAB)
            c = 't';
        else if (print_line[ix] == CH_BLANK)
            c = 'b';
        else 
            c = print_line[ix];
        putchar(c);
        
        /* Printing actual boundary */
        if (ix == boundary - 1 || print_line[ix] == CH_TAB)
        {
            boundary = boundary + TAB;
            putchar('|');
        }
        ix++;
    }
    putchar('\n');
    return;
}
       