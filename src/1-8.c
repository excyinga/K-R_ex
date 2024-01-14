/* Write a program to count blanks, tabs, and newlines.  */

#include <stdio.h>

int main()
{
    int nl, nt, nb = nt = nl = 0;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            nl++;
        if (c == '\t')
            nt++;
        if (c == ' ')
            nb++;
    }
    printf("\nnl: %d\nnt: %d\nnb: %d\n", nl, nt, nb);
    return 0;
}