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
    {"int a[10]]", FALSE},
    {"float fun(){}", TRUE},
    {"[]{{int a;}}", TRUE},
    {"/*asdsdas*/", TRUE},
    {"/*/**/*/", FALSE},
    {"/*/**/", TRUE}
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
    for(; test[i] != '\0'; i++)
    {
        if (test[i] == '[')
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
    }
    return TRUE;
}

int main()
{
    int i = 0;
    for (; i < sizeof(test_cases) / sizeof(test_case); i++)
    {
        if (Validate(test_cases[i].test) == test_cases[i].is_passed)
        {
            printf("Test #%d passed\n", i + 1);
        }
        else
        {
            printf("Test #%d didn't pass\n", i + 1);
        }
    }
    return 0;
}