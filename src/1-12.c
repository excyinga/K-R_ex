/* Write a program that prints its input one word per line.  */

#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    char c, _state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == '\t' || c == ' ')
        {
            if (_state)
            {
                putchar('\n');
                _state = OUT;
            }
        }
        else
        {
            _state = IN;
            putchar(c);
        }
    }
    return 0;
}