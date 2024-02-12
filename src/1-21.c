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
#define CH_TAB_STOP '|'

int len = INIT;
char line[MAX_LINE], new_line[MAX_LINE];

int GetLine(char line[], int max);
void Entab(void);
void PrintLine(char print_line[]);

int main()
{
    extern int len;
    extern char line[];
    extern char new_line[];
    while ((len = GetLine(line, MAX_LINE)))
    {
        printf("Line: ");
        PrintLine(line);
        Entab();
        printf("New line: ");
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
    int i, j = i = INIT;
    int current_ch = INIT;
    while (line[i] != '\0')
    {
        if (line[i] == CH_BLANK || line[i] == CH_TAB )
        {
            int f_ch = current_ch;
            for (; line[i] == CH_BLANK || line[i] == CH_TAB; i++)
            {
                if (line[i] == CH_TAB || current_ch == TAB - 1)
                {
                    new_line[j] = CH_TAB;
                    j++;
                    current_ch = f_ch = 0;
                     
                }
                else if (line[i + 1] != CH_BLANK && line[i + 1] != CH_TAB)
                {
                    while (f_ch != current_ch + 1)
                    {
                        new_line[j] = CH_BLANK;
                        j++;
                        f_ch++;
                    }
                }
                else
                    current_ch++;
            }
        }
        else
        {
            new_line[j] = line[i];
            j++;
            i++;
        }

        if (current_ch == TAB - 1)
            current_ch = 0;
        else
            current_ch++;
    }
    new_line[j] = '\0';
    return; 
}
void PrintLine(char print_line[])
{ 
    int ix = 0;
    int tab_stop = 0;
    while (print_line[ix] != '\0')
    {
        if (print_line[ix] == CH_BLANK)
        {
            putchar('B');
            putchar('L');
        }
        else if (print_line[ix] == CH_TAB) 
        {
            putchar('T');
            putchar('B');
        }
        else    
            putchar(print_line[ix]);
        tab_stop++;
        if (print_line[ix] == CH_TAB || tab_stop == TAB)
        {
            putchar(CH_TAB_STOP);
            tab_stop = 0;
        }
        ix++;
    }
    putchar('\n');
    return;
}