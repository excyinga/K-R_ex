/* Write a program to print a histogram of the frequencies of different characters
in its input. */

#include <stdio.h>

#define ARRAY_SIZE 96

int main()
{
    char c, array[ARRAY_SIZE] = {0};
    int ix, jx, max = 0;
    while ((c = getchar()) != EOF)
    {
        if (c >= 32)
        {
            array[c - 32]++;
            if (array[c - 32] > max)
            {
                max = array[c - 32];
            }
        }
    }
    for (ix = 0; ix <= max; ix++)
    {
        for (jx = 0; jx < ARRAY_SIZE; jx++)
        {
            if (array[jx])
            {
                putchar(' ');
                if (ix != max)
                {
                    if (array[jx] >= max - ix)
                        putchar('|');
                    else
                        putchar(' ');
                }
                else
                    putchar(jx + 32);
                putchar(' ');
            }
        }
        putchar('\n');
    }
    return 0;
}