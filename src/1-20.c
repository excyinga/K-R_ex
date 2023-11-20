/* Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter? */

#include <stdio.h>

#define TAB 8
#define MAX_LINE 1024

int len = 0;
char line[MAX_LINE] = {0}, new_line[(MAX_LINE - 1) * TAB + 1] = {0};

int GetLine(char [], int);
void Detab(void);
void PrintLine(char []);

int main()
{
    extern int len;
    extern char line[];
    extern char new_line[];
    while ((len = GetLine(line, MAX_LINE)))
    {
        PrintLine(line);
        Detab();
        PrintLine(new_line);
    }
    return 0;
}

int GetLine(char line[], int max)
{
    int ix;
    char c;
    for (ix = 0; ix < max - 1 && (c = getchar()) != '\n' && c != EOF; ix++)
        line[ix] = c;
    line[ix] = '\0';
    return ix;
}
void Detab(void)
{
    int ix, jx = ix = 0;
    extern char line[];
    extern char new_line[];
    while (line[ix] != '\0')
    {
        if (line[ix] == '\t')
        {
            int kx = TAB;
            while (kx <= jx)
                kx = kx + TAB;
            for (; jx < kx; jx++)
                new_line[jx] = ' ';
            jx--; 
        }
        else
            new_line[jx] = line[ix];
        ix++;
        jx++;
    }
    new_line[jx] = '\0';
    return;
}
void PrintLine(char line[])
{ 
    int ix = 0;
    char c;
    while (line[ix] != '\0')
    {
        if (line[ix] == '\t')
            c = 't';
        else if (line[ix] == '\b')
            c = 'b';
        else 
            c = line[ix];
        putchar('\'');
        putchar(c);
        putchar('\'');
        ix++;
    }
    putchar('\n');
    return;
}
       