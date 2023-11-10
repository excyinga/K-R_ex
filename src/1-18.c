/* Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines. */

/* #include <stdio.h>

#define MAX_LINE 1024
#define TRUE 1
#define FALSE 0

int GetLine(char [], int);
void RemoveTrailingBlanks(char [], int);

int main()
{
    int len;
    char line[MAX_LINE] = {0};
    while ((len = GetLine(line, MAX_LINE)))
    {
        printf("Not edited line: \'%s\'\n");
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
        if (ix < max - 1)
            line[ix] = c;
        ix++;
    }
    line[ix] = '\0';
    return ix;
}
void RemoveTrailingBlanks(char line[], int len)
{
    char _state = FALSE;
    int ix, tmp;
    for (ix = tmp = 0; line[ix] != '\0'; ix++)
    {
        
    }
} */