/* Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.  */

#include <stdio.h>

#define LINE_LENGTH 1024

char line[LINE_LENGTH], new_line[LINE_LENGTH];
int len;

int GetLine(int max_length);
void PrintLine(char line[]);

int main()
{
    extern char line[];
    extern int len;
    while ((len = GetLine(LINE_LENGTH)) != 0)
    {
        PrintLine(line);  
    }
    return 0;
}

int GetLine(int max_length)
{
    extern char line[];
    int i = 0;
    char c;
    while (i < max_length - 1 && (c = getchar()) != EOF)
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}
int RemoveComments()
{
    extern char line[], new_line[];
    int i, j = 0;
    return 1;
}
void PrintLine(char line[])
{
    int i = 0;
    while (line[i] != '\0')
    {
        putchar(line[i]);
        i++;
    }
    return;
}

