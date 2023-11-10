/* Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text.  */

#include <stdio.h>

#define MAX_LINE 1024

int GetLine(char [], int);
void CopyLine(char [], char []);

int main()
{
    int len, max = 0;
    char line[MAX_LINE] = {0}, longest_line[MAX_LINE] = {0};
    while ((len = GetLine(line, MAX_LINE)) != 0)
    {
        if (len > max)
        {
            max = len;
            CopyLine(line, longest_line);
        }
    }
    printf("Longest line: %s\nLength of arbitrary long input lines : %d\n", longest_line, max);
    return 0;
}

int GetLine(char line[], int max)
{
    char c;
    int ix = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (ix < max - 1)
            line[ix] = c;
        ix++;
    }
    if (ix > max - 1)
        line[max - 1] = '\0';
    else
        line[ix] = '\0';
    return ix;
}
void CopyLine(char from[], char to[])
{
    int ix;
    for (ix = 0; from[ix] != '\0'; ix++)
    {
        to[ix] = from[ix];
    }
    to[ix] = '\0';
    return;
}



