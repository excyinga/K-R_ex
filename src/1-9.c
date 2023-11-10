/* Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.  */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main()
{
    char c, _state = TRUE;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' && _state)
        {
            putchar(c);
            _state = FALSE;
        }
        else if (c != ' ')
        {
            putchar(c);
            _state = TRUE;
        }
    }
    return 0;
}