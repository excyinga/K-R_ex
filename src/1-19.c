/* Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time.  */

#include <stdio.h> 

#define MAX_LINE 1024

int GetLine(char [], int);
void ReverseString(char [], int);

int main()
{
    int len;
    char line[MAX_LINE] = {0};
    while ((len = GetLine(line, MAX_LINE)))
    {
        printf("Not edited line: %s\n", line);
        ReverseString(line, len);
        printf("Edited line: %s\n", line);
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
void ReverseString(char line[], int len)
{
    int ix, tmp;
    for (ix = 0; ix < len / 2; ix++)
    {
        tmp = line[ix];
        line[ix] = line[len - ix - 1];
        line[len - ix - 1] = tmp;
    }
    return;
}
 