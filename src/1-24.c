/* Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full
generality.) */

#include <stdio.h>

#define FALSE   0
#define TRUE    1
#define STACK_CAPACITY 16

typedef unsigned char bool;
typedef char * string;
typedef struct test_case test_case;
typedef struct stack_t stack_t;

struct test_case
{
    string test;
    bool is_passed;
};
struct stack_t
{
    char data[STACK_CAPACITY];
    int sp;
};

test_case test_cases[] =
{
    {"[]", TRUE},
    {"[", FALSE},
    {"{", FALSE},
    {"(", FALSE},
    {"]", FALSE},
    {"}", FALSE},
    {")", FALSE},
    {"{}", TRUE},
    {"()", TRUE},
    {"[[]", FALSE},
    {"([)]", FALSE},
    {"{{(}}", FALSE},
    {"{}}", FALSE},
    {"(({))", FALSE},
    {"((()))", TRUE},
    {"({[][})]", FALSE},
    {"{([(){{()[]}}])}", TRUE},
    {"int a[10]]", FALSE},
    {"float fun(){}", TRUE},
    {"[]{{int a;}}", TRUE},

    {"/*safasdfasdfdsafasdfsadfasd*/", TRUE},
    {"//*safasdf\nasdfdsafasdfsadfasd*/", FALSE},
    {"( /* ) */", FALSE},
    {"( /* ) */)", TRUE},
    {"//asdfasdfasddsaf", FALSE},
    {"/*aasdfadsfasd*/*/", FALSE}

};

void push(char element, stack_t * stack)
{   
    stack->data[stack->sp] = element;
    stack->sp++;
    return;
}
char pop(stack_t * stack)
{
    stack->sp--;
    return stack->data[stack->sp];
}
bool Validate(string test)
{
    stack_t stack = {.sp = 0};
    int i = 0;
    bool is_comment = FALSE;
    for(; test[i] != '\0'; i++)
    {
        if (!is_comment)
        {
            if (test[i] == '[' || test[i] == '{' || test[i] == '(')
            {
                push(test[i], &stack);
            }
            else if (test[i] == ']')
            {
                if (stack.sp == 0 || pop(&stack) != '[')
                {
                    return FALSE;
                }
            }
            else if (test[i] == '}')
            {
                if (stack.sp == 0 || pop(&stack) != '{')
                {
                    return FALSE;
                }
            }
            else if (test[i] == ')')
            {
                if (stack.sp == 0 || pop(&stack) != '(')
                {
                    return FALSE;
                }
            }
            else if (test[i] == '/' && test[i + 1] == '*')
            {
                is_comment = TRUE;
                i++;
            }
        }
        else
        {
            if (test[i] == '*' && test[i + 1] == '/')
            {
                is_comment = FALSE;
                i++;
            }
        }
    }

    if (stack.sp != 0)
        return FALSE;
    return TRUE;
}

int main()
{
    int i = 0;
    for (; i < sizeof(test_cases) / sizeof(test_case); i++)
    {
        if (Validate(test_cases[i].test) == test_cases[i].is_passed)
        {
            printf("Test #%-2d passed\n", i + 1);
        }
        else
        {
            printf("Test #%-2d didn't pass\n", i + 1);
        }
    }
    return 0;
}