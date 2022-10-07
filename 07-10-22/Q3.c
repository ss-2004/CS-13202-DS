// Shresth Sonkar
// 20214272
// Q3

#include <stdio.h>
#include <string.h>

int top = 0;

int isOpening(char ch)
{
    switch (ch)
    {
    case '{':
    case '[':
    case '(':
        return 1;
    default:
        return 0;
    }
}

int valid(char *stack, char *str, int n)
{
    for (int i=0; i<n; i++)
    {
        char ch = str[i];
        if (isOpening(ch))
        {
            if (top == n)
                return 0;
            else
                stack[top++] = ch;
        }
        else
        {
            if (top == 0)
                return 0;
            char t = stack[top - 1];

            if (t == '(' && ch == ')' || t == '[' && ch == ']' || t == '{' && ch == '}')
                top--;
            else
                return 0;
        }
    }
    return top == 0;
}

int main()
{
    char exp[32];
    printf("Enter expression : ");
    scanf("%[^\n]%*c", exp);
    char stack[strlen(exp)];

    if (valid(stack, exp, strlen(exp)))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}

/* OUTPUTS

~/20214272/DS/07-10-22 $ gcc Q2.c -o q2
~/20214272/DS/07-10-22 $ ./q2
Enter a string : hello world
Reverse : dlrow olleh
~/20214272/DS/07-10-22 $ ./q2
Enter a string : racecar
Reverse : racecar
~/20214272/DS/07-10-22 $

*/
