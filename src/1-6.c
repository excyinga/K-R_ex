/* Verify that the expression getchar() != EOF is 0 or 1. */

#include <stdio.h>

int main()
{
    printf("Getchar expr: %d\n", getchar() != EOF);
    
    return 0;
}