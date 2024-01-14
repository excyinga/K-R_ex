/* How would you test the word count program? What kinds of input are most
likely to uncover bugs if there are any? */

#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    char c, _state = OUT;
    int wc = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            _state = OUT;
        }
        else if (_state == OUT)
        {   
            wc++;
            _state = IN;
        }
    }
    printf("wc: %d\n", wc);
    return 0;
}
