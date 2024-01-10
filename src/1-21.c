/* Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?  */

#include <stdio.h>

#define INIT 0
#define FALSE 0
#define TRUE 1
#define TAB 8
#define MAX_LINE 1024
#define CH_BLANK ' '
#define CH_TAB '\t'

int len = INIT;
char line[MAX_LINE], new_line[MAX_LINE];

int GetLine(char line[], int max);
void Entab(void);
void PrintLine(char arg[], char print_line[]);

int main()
{
    extern int len;
    extern char line[];
    extern char new_line[];
    while ((len = GetLine(line, MAX_LINE)))
    {
        PrintLine(line);
        Entab();
        PrintLine(new_line);
    }
    return 0;
}
int GetLine(char line[], int max)
{
    char c;
    int ix = INIT;
    while (ix < max - 1 && (c = getchar()) != EOF && c != '\n')
    {
        line[ix] = c;
        ix++;
    } 
    line[ix] = '\0';
    return ix;
}
void Entab(void)
{
    extern char line[], new_line[];
    int line_ix, new_line_ix = line_ix = INIT;
    
    while (line[line_ix] != '\0')
    {
        
    }

    new_line[new_line_ix] = '\0';
    return; 
}
void PrintLine(char arg[], char print_line[]);
{ 
    extern char new_line[];
    


    putchar('\n');
    return;
}