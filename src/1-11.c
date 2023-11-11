/* How would you test the word count program? What kinds of input are most
likely to uncover bugs if there are any? */

#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    char c, _state = IN;
    int wc = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
            _state = IN;
        else if (_state)
        {
            wc++;
            _state = OUT;
        }
    }
    printf("wc: %d\n", wc);
    return 0;
}

/* int main()
{
    char c;
    int wc = 0;
    while ((c = getchar()) != EOF)
    {
        if (c != '\n' && c != '\t' && c != ' ')
        {
            while ((c = getchar()) != '\n' && c != '\t' && c != ' ' && c != EOF);
            wc++;
        }
    }
    printf("wc: %d\n", wc);
    return 0;
} */ 