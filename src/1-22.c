/* Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column */

/* 01234567890123456789012345678901 // length = 32 */

#include <stdio.h>

#define INIT 0
#define MAX_LINE 1024
#define LINE_BOUND 32
#define TAB 8
#define CH_TAB '\t'
#define CH_BLANK ' '
#define CH_NEW_LINE '\n'

char line[MAX_LINE] = {INIT}, new_line[MAX_LINE * TAB + 32] = {INIT};

int GetLine(int);
void Fold(void);

void PrintLine(char []);
int WordLength(char * line, int position);

int main()
{
    extern char line[], new_line[];
    int len = INIT;
    while ((len = GetLine(MAX_LINE)) != 0)
    {
        Fold();
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
void Fold(void)
{
    extern char line[], new_line[];
    int line_ix, new_line_jx = line_ix = INIT;
    int current_boundary_index = LINE_BOUND;
    int word_length;
    while (line[line_ix] != '\0')
    {  
        if (line[line_ix] > 32 && line[line_ix] < 127)
        {
            word_length = WordLength(line, line_ix);
            if (word_length + new_line_jx < current_boundary_index)
            {
                
            }
        }
    }   
    new_line[new_line_jx] = '\0';
    return;
}
void PrintLine(char line[])
{
    int ix = INIT;
    for (; line[ix] != '\0'; ix++)
    {
        putchar(line[ix]);
    }
    return;
}
int WordLength(char * line, int position)
{
    int word_length = INIT;
    for(; line[position] > 32 && line[position] < 127; position++, word_length++);
    return word_length;
}