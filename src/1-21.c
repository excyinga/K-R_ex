/* Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?  */

#include <stdio.h>

#define INIT 0
#define FALSE 0
#define TRUE 1
#define FLAG_CHR 0
#define FLAG_BLK 1
#define FLAG_TAB 2
#define TAB 8
#define MAX_LINE 1024
#define CH_BLANK ' '
#define CH_TAB '\t'

int len = INIT;
char line[MAX_LINE] = {INIT}, new_line[MAX_LINE] = {INIT};

int GetLine(char [], int);
void Entab(void);
void PrintLine(char []);

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
    int ix, jx, bx = jx = ix = INIT;
    extern char line[], new_line[];
    while (line[ix] != '\0')
    {
        if (line[ix] == CH_BLANK || line[ix] == CH_TAB)
        {
            for (bx = ix; line[ix] == CH_BLANK || line[ix] == CH_TAB; ix++)
            {
                if (ix % TAB == TAB - 1 || line[ix] == CH_TAB)
                {
                    new_line[jx++] = CH_TAB;
                    bx = ix + 1;
                }
                else if (line[ix + 1] != CH_BLANK && line[ix + 1] != CH_TAB)
                {
                    while (line[bx] == CH_BLANK)
                    {
                        new_line[jx++] = CH_BLANK;
                        bx++;
                    }
                }
            }
            ix = ix - 1;
        }
        else
        {
            new_line[jx++] = line[ix];
        }
        ix++;
    }
    new_line[jx] = '\0';
    return;

}
void PrintLine(char line[])
{ 
    int ix = INIT;
    char c;
    while (line[ix] != '\0')
    {
        if (line[ix] == CH_TAB)
            c = 't';
        else if (line[ix] == CH_BLANK)
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
       