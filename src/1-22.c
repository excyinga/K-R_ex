/* Write a program to "fold" long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column */

#include <stdio.h>
#include <stdlib.h>

#define FALSE       0
#define TRUE        1
#define MAX_LINE    1024
#define LINE_BOUND  32
#define TAB         8
#define CH_TAB      '\t'
#define CH_BLANK    ' '
#define CH_NEW_LINE '\n'
#define X(test, output) {__LINE__, test, output}
#define countof(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned char bool;
typedef char* string;
typedef struct test_case test_case;

struct test_case
{
    int line;
    string test;
    string output;
};

test_case test_cases[] =
{
    X("a", "a"),
    X("This is a line with several words. Thisisalinewithonelongword.", "This is a line with several\nwords.\nThisisalinewithonelongword."),
    X("12345678901234567890123456789012", "12345678901234567890123456789012"),
    X("12345678901234567890123456789 12", "12345678901234567890123456789 12"),
    X("123456789012345678901234567890123", "12345678901234567890123456789012\n3"),
    X("12345678901234567890123456789012 4", "12345678901234567890123456789012\n 4"),
    X("12345678901234567890123456789012  5", "12345678901234567890123456789012\n  5"),

    X(" 1", " 1"),
    X(" 2345678901234567890123456789012", " 2345678901234567890123456789012"),
    X(" 23456789012345678901234567890123", " 2345678901234567890123456789012\n3"),
    X("  3456789 1234567890123456789 123", "  3456789 1234567890123456789\n123"),

    X("                                ", "                                "),
    X("                                 ", "                                \n "),

    X("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123",\
"12345678901234567890123456789012\n\
34567890123456789012345678901234\n\
56789012345678901234567890123456\n\
78901234567890123456789012345678\n\
90123456789012345678901234567890\n\
12345678901234567890123456789012\n\
34567890123456789012345678901234\n\
56789012345678901234567890123456\n\
78901234567890123456789012345678\n\
90123456789012345678901234567890\n\
12345678901234567890123456789012\n\
34567890123456789012345678901234\n\
56789012345678901234567890123456\n\
78901234567890123456789012345678\n\
90123456789012345678901234567890\n\
12345678901234567890123456789012\n\
34567890123456789012345678901234\n\
56789012345678901234567890123456\n\
78901234567890123456789012345678\n\
90123456789012345678901234567890\n\
12345678901234567890123456789012\n\
34567890123456789012345678901234\n\
56789012345678901234567890123456\n\
78901234567890123456789012345678\n\
90123456789012345678901234567890\n\
12345678901234567890123456789012\n\
34567890123456789012345678901234\n\
56789012345678901234567890123456\n\
78901234567890123456789012345678\n\
90123456789012345678901234567890\n\
12345678901234567890123456789012\n\
3456789012345678901234567890123"),

    X("Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s.",\
    "Lorem Ipsum is simply dummy text\n of the printing and typesetting\n industry. Lorem Ipsum has been\nthe industry's standard dummy\ntext ever since the 1500s."),

    X("12345678901234567890123\t9012", "12345678901234567890123\t9012"),
    X("12345678901234567890123\t\t12", "12345678901234567890123\t\t\n12"),
    X("a b", "a b"),

    X("123456789012345678901234\t1", "123456789012345678901234\t\n1"),
    X("123456789012345678901234\t  12\t", "123456789012345678901234\t\n  12\t"),

    X("123456789012345678901234\t1", "123456789012345678901234\t\n1"),

    X("a\tb", "a\tb"),

    X("", "")
};

string Fold(string test_string);
bool Validate(string str1, string str2);
void PrintLine(string str);
void Panic(string str);

int main()
{
    string output_string = NULL;
    int i = 0;
    for (; i < countof(test_cases); i++)
    {
        output_string = Fold(test_cases[i].test);
        if (Validate(output_string, test_cases[i].output))
        {
            printf("Test #%-3d at line %d is not passed\n", i, test_cases[i].line);
            printf("OS: ");
            PrintLine(output_string);
            putchar('\n');
            printf("TS: ");
            PrintLine(test_cases[i].output);
            putchar('\n');
        }
        else
            printf("Test #%-3d at line %d passed\n", i, test_cases[i].line);
        free(output_string);
    }
    return 0;   
}
string Fold(string test_string)
{

    int string_size = 0;
    for (; test_string[string_size] != '\0'; string_size++);
    if (string_size > MAX_LINE - 1)
        Panic(test_string);
    string output_string = NULL;
    output_string = malloc(sizeof(char) * MAX_LINE + MAX_LINE / LINE_BOUND);
    int i, j, k, t = k = j = i = 0;
    int to_border = 0, l_ch = 0;
    bool _state = FALSE;
    while (test_string[i] != 0)
    {
        to_border++;
        if ((test_string[i] == CH_TAB || test_string[i] == CH_BLANK) && _state == TRUE)
        {
            if (test_string[i] == CH_TAB)
            {
                while (t < to_border)
                    t = t + TAB;
                for (; to_border < t; to_border++);
                l_ch = i + 1;
            }
            else
            {
                l_ch = i;
            }
        }
        else
        {
            _state = TRUE;
        }
        if (to_border == LINE_BOUND || test_string[i + 1] == '\0')
        {
            if (l_ch <= k || test_string[i + 1] == '\0' || test_string[i + 1] == CH_TAB || test_string[i + 1] == CH_BLANK || _state == FALSE)
                l_ch = i + 1;
            for (; k < l_ch; k++, j++)
                output_string[j] = test_string[k];
            if (test_string[i + 1] != '\0')
            {
                output_string[j] = CH_NEW_LINE;
                j++;
            }
            if (test_string[l_ch] == CH_BLANK && l_ch <= i)
            {
                i = k;
                k++;
            }
            to_border = 0;
            t = 0;
            _state = FALSE;
        }
        i++;
    }
    output_string[j] = '\0';
    return output_string;
}
bool Validate(string str1, string str2)
{
    int i = 0;
    while (TRUE)
    {
        if (str1[i] != str2[i])
            return TRUE;
        else if (str1[i] == '\0')
            return FALSE;
        i++;
    }
}
void PrintLine(string str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        putchar('\'');
        putchar(str[i]);
        putchar('\'');
        i++;
    }
    return;
}
void Panic(string str)
{
    printf("Panic at line: \'%s\'\n", str);
    exit(1);
    return;
}