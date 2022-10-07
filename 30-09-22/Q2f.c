// Shresth Sonkar
// 32214272
// Q2f

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define l 32

void input();
void push(char c);
char pop();
int isOperator(char x);
void pre2post();

char str[l], stack[l];
int top = -1;

void input()
{
    printf("Prefix : ");
    scanf("%[^\n]%*c", str);
}

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int isOperator(char x)
{
    switch(x)
    {
        case '+' :
        case '-' :
        case '/' :
        case '*' :
        case '^' : 
            return 1;
    }
    return 0;
}

void pre2post()
{
    int n=strlen(str), i, j = 0;
    char c[l], a, b, op;

    for (i = 0; i < l; i++)
        stack[i] = '\0';

    for (i=0; i<n; i++)
    {
        if(isOperator(str[i]))
            push(str[i]);
        else
        {
            c[j++] = str[i];
            while ((top != -1) && (stack[top] == '#'))
            {
                a = pop();
                c[j++] = pop();
            }
            push('#');
        }
    }
    
    c[j] = '\0';
    printf("Postfix : %s\n", c);
}

int main()
{
    input();
    pre2post();
    return 0;
}

/* OUTPUTS

~/Desktop/CSE/ASSGN/DSLAB/30-09-22 $ clang Q2f.c -o q2f
~/Desktop/CSE/ASSGN/DSLAB/30-09-22 $ ./q2f
Prefix : *-A/BC-/DEF
Postfix : ABC/-DE/F-*
~/Desktop/CSE/ASSGN/DSLAB/30-09-22 $

*/