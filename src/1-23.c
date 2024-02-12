/* Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.  */

#include <stdio.h>
#include <stdlib.h>

#define FALSE   0
#define TRUE    1
#define LINE_LENGTH 1024
#define X(data, output) {__LINE__, data, output}
#define countof(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned char bool;
typedef char * string;
typedef struct test_case test_case;

struct test_case
{
    int line;
    string test;
    string output;
};

test_case test_cases[] =
{
    X("", ""),
    X("/**/", ""),
    X("/*", ""),
    X("/*dsafsdafsda", ""),
    X("/*asdfasdfasdfadsfasdfsadf*/", ""),

    X("acdf", "acdf"),
    X("acdf/*12345", "acdf"),
    X("acdf/*asdfsdafsdafsd*/", "acdf"),
    X("asdfad/**/", "asdfad"),

    X("'//'", "'//'"),
    X("'//'a", "'//'a"),
    X("'/**/'", "'/**/'"),
    X("'/*'", "'/*'"),
    X("'/*asdfdsa*/'", "'/*asdfdsa*/'"),
    X("\"//\"", "\"//\"")
};

string RemoveComments(string current_test)
{
    int str_len_current_test = 0; 
    while (current_test[str_len_current_test] != '\0')
    {
        str_len_current_test++;
    }
    string new_line = malloc(sizeof(char) * (str_len_current_test + 1));
    int i = 0;
    int j = 0;
    bool is_s_comment = FALSE;
    bool is_d_comment = FALSE;
    bool is_s_quote = FALSE;
    bool is_d_quote = FALSE;
    while (current_test[i] != '\0')
    {
        if (is_d_comment || is_s_comment)
        {
            if (is_s_comment)
            {
                if (current_test[i] == '\n')
                {
                    is_s_comment = FALSE;
                }
            }
            else
            {
                if (current_test[i] == '*' && current_test[i + 1] == '/')
                {
                    is_d_comment = FALSE;
                    i++;
                }
            }
        }
        else if (current_test[i] == '/' && current_test[i + 1] == '*' && !is_s_quote && !is_d_quote)
        {
                is_d_comment = TRUE;
                i++;
        }
        else if (current_test[i] == '/' && current_test[i + 1] == '/' && !is_s_quote && !is_d_quote)
        {
            is_s_comment = TRUE;
            i++;
        }
        else
        {
            if (current_test[i] == '\'')
            {
                if (is_s_quote == FALSE)
                {
                    is_s_quote = TRUE;
                }  
                else
                {
                    is_s_quote = FALSE;
                }
            }
            else if (current_test[i] == '\"')
            {
                if (is_d_quote == FALSE)
                {
                    is_d_quote = TRUE;
                }
                else
                {
                    is_d_quote = FALSE;
                }
            }
            new_line[j] = current_test[i];
            j++;
        }
        i++;
    }
    new_line[j] = '\0';
    return new_line;
}
bool Validate(char * str1, char * str2)
{
    int i = 0;
    while (TRUE)
    {
        if (str1[i] != str2[i])
        {
            return FALSE;
        }
        else if (str1[i] == '\0')
        {
            return TRUE;
        }
        i++;
    }
}

int main()
{
    int i = 0;
    bool all_test_passed = TRUE;
    char * cleared_string = NULL;
    while (i < countof(test_cases))
    {
        cleared_string = RemoveComments(test_cases[i].test);
        if (Validate(cleared_string, test_cases[i].output))
        {
            printf("Test #%-2d at line %d passed\n", i + 1, test_cases[i].line);
        }
        else
        {
            printf("-----------------------------------------\n");
            all_test_passed = FALSE;
            printf("Test #%-2d at line %d isn't pass\nTest: %s\nExpected : %s\nResult : %s\n", i + 1, test_cases[i].line, test_cases[i].test, test_cases[i].output, cleared_string);
            printf("-----------------------------------------\n");
        }
        free(cleared_string);
        i++;
    }
    if (all_test_passed)
        printf("All test are passed\n");
    return 0;
}


