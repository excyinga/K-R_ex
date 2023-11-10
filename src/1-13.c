/* Write a program to print a histogram of the lengths of words in its input. 
It is easy to draw the histogram with the bars horizontal; 
a vertical orientation is more challenging.  */

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define ARRAY_SIZE 10

int main()
{
    int arr_n[ARRAY_SIZE] = {0}, cn = 0, ix_i, ix_j = ix_i = 0, max = 0;
    char c, _state = FALSE;
    while ((c = getchar()))
    {
        if (c == ' ' || c == '\t' || c == '\n' || c == EOF)
        {
            if (_state)
            {
                if (cn > ARRAY_SIZE - 1)
                    ++arr_n[ARRAY_SIZE - 1];                
                else
                    ++arr_n[cn - 1];
                cn = 0;
                _state = FALSE;
            }
            if (c == EOF)
            {
                break;
            }
        }
        else 
        {
            cn++;
            _state = TRUE;
        }
    }
    for (ix_i = 0; ix_i < ARRAY_SIZE; ix_i++)
    {
        if (arr_n[ix_i] > max)
            max = arr_n[ix_i];
    }
    putchar('\n');
    ix_i = 0;
    while (ix_i < max)
    {
        while (ix_j < ARRAY_SIZE)
        {
            putchar(' ');
            if (arr_n[ix_j] >= max - ix_i)
                putchar('|');
            else
                putchar(' ');
            putchar(' ');
            ++ix_j;
        }
        putchar('\n');
        ++ix_i;
        ix_j = 0;
    }
    for (ix_i = 0; ix_i < ARRAY_SIZE; ix_i++)
    {
        putchar(' ');
        printf("%d", ix_i + 1);
        putchar(' ');
    }
    putchar('\n');
    return 0;
}