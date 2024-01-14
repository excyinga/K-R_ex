/* Rewrite the temperature conversion program of Section 1.2 to use a function
for conversion.  */

#include <stdio.h>

int ConvFahrToC(int);

int main()
{
    int ix;
    for (ix = 0; ix <= 300; ix += 20)
        printf("%-4d %-3d\n", ix, ConvFahrToC(ix));
    return 0;
}

int ConvFahrToC(int Fahr)
{
    return 5 * (Fahr - 32) / 9;
}