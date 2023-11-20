/* Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines. */

#include <stdio.h>

#define MAX_LINE 1024

int GetLine(char [], int);
void RemoveTrailingBlanks(char [], int);

int main()
{
    int len;
    char line[MAX_LINE] = {0};
    while ((len = GetLine(line, MAX_LINE)))
    {
        printf("Not edited line: \'%s\'\n", line);
        RemoveTrailingBlanks(line, len);
        printf("Edited line: \'%s\'\n", line);
    }
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
void RemoveTrailingBlanks(char line[], int len)
{
    int ix, tmp_ix;
    for (ix = tmp_ix = 0; line[ix] != '\0'; ix++)
    {
        if (line[ix] != ' ' && line[ix] != '\t')
            tmp_ix = ix + 1;
    }
    line[tmp_ix] = '\0';
    return;
}