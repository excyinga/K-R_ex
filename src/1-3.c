/* Modify the temperature conversion program to print a heading above the table */

#include <stdio.h>

int main()
{
    int fahr, celsius, lower, upper, step;

    lower = 0, step = 20, upper = 300;
    fahr = lower;

    printf("%3s %2s\n", "Fahr", "C");
    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d  %-6d\n", fahr, celsius);

        fahr = fahr + step;
    }   
    
    return 0;
}