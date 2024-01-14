/* Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full
generality.) */

#include <stdio.h>
#include <stdlib.h>

#define FALSE   0
#define TRUE    1
#define STACK_CAPACITY 64
#define X(data, is_passed) {__LINE__, data, is_passed}

typedef unsigned char bool;
typedef char * string;
typedef struct test_case test_case;
typedef struct stack_t stack_t;

struct test_case
{
    int line;
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
    X("[]", TRUE),
    X("[", FALSE),
    X("{", FALSE),
    X("(", FALSE),
    X("]", FALSE),
    X("}", FALSE),
    X(")", FALSE),
    X("))", FALSE),
    X(")]", FALSE),
    X("{)", FALSE),
    X("{}", TRUE),
    X("{{()}}", TRUE),
    X("{{()}}[]", TRUE),
    X("{{()}}[]]", FALSE),
    X("()", TRUE),
    X("[[]", FALSE),
    X("([)]", FALSE),
    X("{{(}}", FALSE),
    X("{}}", FALSE),
    X("(({))", FALSE),
    X("((()))", TRUE),
    X("({[][})]", FALSE),
    X("{([(){{()[]}}])}", TRUE),
    X("int a[10]]", FALSE),
    X("float fun(){}", TRUE),
    X("[]{{int a;}}", TRUE),
    X("{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}", TRUE),
    X("{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}", TRUE),
    X("{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}", FALSE),
    X("{({({({({{[]}})})})})}", TRUE),

    X("('(')", TRUE),
    X("'", FALSE),
    X("''", TRUE),
    X("(''('')", FALSE),
    X("('\"(\"')", TRUE),

    X("\"\"", TRUE),
    X("\"sadfsad\"asdfsadf\"sdfsad\"", TRUE),
    X("\"", FALSE),
    X("\"\"\"", FALSE),
    X("\"{}", FALSE),
    X("\"{\"", TRUE),
    X("{\"(}\"}", TRUE),
    X("(\"{}\"}", FALSE),
    X("{\"{\"}\"}\"(\")\")", TRUE),
    
    X("/", TRUE),
    X("//", TRUE),
    X("///", TRUE),
    X("////", TRUE),
    X("//asdf", TRUE),
    X("//sadfsadfdasasfasdfsdfsdfasdfasdfasdfsdsadfasdfasdfsadfsadfdsafsa\n", TRUE),
    X("///*asdf*/", TRUE),
    X("//asd/*f*///*asdfsdfsad*/\n*/", FALSE),
    X("//asd/*f*///*asdfsdfsad*/\n/*", FALSE),
    X("/*", FALSE),
    X("/**/", TRUE),
    X("*/", FALSE),
    X("/*asdfasdfasdfsadfsda//asdfdsafds*/", TRUE),
    X("/*asdfds**/", TRUE),
    X("/*asdfds*/*/", FALSE),
    X("/*/*asdfds*/*/", FALSE),
    X("/*//*/", TRUE)

};

void Panic(char * str)
{
    printf("%s\n", str);
    exit(1);
}

void Push(char element, stack_t * stack)
{   
    if (stack->sp == STACK_CAPACITY)
    {
        Panic("Stack is overflowed");
        return;
    }
    stack->data[stack->sp] = element;
    stack->sp++;
    return;
}
char Pop(stack_t * stack)
{
    if (stack->sp == 0)
        return 0;
    stack->sp--;
    return stack->data[stack->sp];
}
bool Validate(string test)
{
    stack_t stack = {.sp = 0};
    int i = 0;
    bool is_single_comments = FALSE; 
    bool is_double_comments = FALSE;
    bool is_single_quotes = FALSE; 
    bool is_double_quotes = FALSE;
    while (test[i] != '\0')
    {
        if (is_single_comments || is_double_comments || is_single_quotes || is_double_quotes)
        {
            if (is_single_comments)
            {
                if (test[i] == '\n')
                {
                    is_single_comments = FALSE;
                }
            }
            else if (is_single_quotes)
            {
                if (test[i] == '\'')
                {
                    is_single_quotes = FALSE;
                }
            }
            else if (is_double_comments)
            {
                if (test[i] == '*' && test[i + 1] == '/')
                {
                    is_double_comments = FALSE;
                    i++;
                }
            }
            else if (is_double_quotes)
            {
                if (test[i] == '\"')
                {
                    is_double_quotes = FALSE;
                }
            }
        }
        else if (test[i] == ']' || test[i] == '}' || test[i] == ')')
        {
            int pop_value = Pop(&stack); 
            if (test[i] == ']' && pop_value != '[' || test[i] == '}' && pop_value != '{' || test[i] == ')' && pop_value != '(')
            {
                return FALSE;
            }
        }
        else
        {
            if (test[i] == '/')
            {
                if (test[i + 1] == '/')
                {
                    is_single_comments = TRUE;
                    i++;
                }
                else if (test[i + 1] == '*')
                {
                    is_double_comments = TRUE;
                    i++;
                }                
            }
            else if (test[i] == '[' || test[i] == '{' || test[i] == '(')
            {
                Push(test[i], &stack);
            }
            else if (test[i] == '*' && test[i + 1] == '/' && is_double_comments == FALSE)
            {
                return FALSE;
            }
            else if (test[i] == '\"')
            {
                is_double_quotes = TRUE;
            }
            else if (test[i] == '\'')
            {
                is_single_quotes = TRUE;
            }
        }
        i++;
    }
    if (is_double_comments || is_single_quotes || is_double_quotes || stack.sp != 0)
        return FALSE;
    return TRUE;
}

int main()
{
    int i = 0;
    bool all_test_passed = TRUE;
    for (; i < sizeof(test_cases) / sizeof(test_case); i++)
    {
        if (Validate(test_cases[i].test) == test_cases[i].is_passed)
        {
            printf("Test #%-2d at line %d passed\n", i + 1, test_cases[i].line);
        }
        else
        {
            all_test_passed = FALSE;
            printf("Test #%-2d at line %d didn't pass: %s\n", i + 1, test_cases[i].line, test_cases[i].test);
        } 
    }
    if (all_test_passed)
        printf("All test are passed\n");
    return 0;
}