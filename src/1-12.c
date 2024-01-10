/* Write a program that prints its input one word per line.  */

#include <stdio.h>

#define TRUE    1
#define FALSE   0

int main()
{
    char c, _new_line = FALSE;
    
    while ((c = getchar()) != EOF)
    {
        if (c != '\t' && c != ' ' && c != '\n')
        {
            putchar(c);
            
            _new_line = TRUE;
        }
        else if (_new_line)
        {
            putchar('\n');
            
            _new_line = FALSE;
        }
    }
    
    return 0;
}