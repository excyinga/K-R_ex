/* Write a program to print the corresponding Celsius to Fahrenheit table. */

#include <stdio.h>

int main()
{
    int fahr, celsius, lower, upper, step;
    lower = 0, step = 20, upper = 300;
    celsius = lower;
    printf("%3s %5s\n", "C", "Fahr");
    while (celsius <= upper)
    {
        fahr = 9 * celsius / 5 + 32;
        printf("%3d  %-6d\n", celsius, fahr);
        celsius = celsius + step;
    }   
    return 0;
}