// Shresth Sonkar
// 20214272
// Q2d

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define l 32

void input();
void push(char c);
char pop();
int isOperator(char x);
void post2pre();

char str[l], stack[l];
int top = -1;

void input()
{
    printf("Postfix : ");
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

void post2pre()
{
    int n=strlen(str), i, j = 0;
    char c[l], a, b, op;

    for (i = 0; i<l; i++)
        stack[i] = '\0';

    for (i=n-1; i>=0; i--)
    {
        if (isOperator(str[i]))
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
    i=0;
    j=strlen(c)-1;
    char d[l];

    while(c[i] != '\0')
        d[j--] = c[i++];
    d[i] = '\0';
    printf("Prefix : %s\n", d);
}

int main()
{
    input();
    post2pre();
    return 0;
}

/* OUTPUTS

~/desktop/cse/ASSGN/DSLAB/30-09-22 $ clang Q2d.c -o q2d
~/desktop/cse/ASSGN/DSLAB/30-09-22 $ ./q2d             
Postfix : ABC/-DE/F-*
Prefix : *-A/BC-/DEF
~/desktop/cse/ASSGN/DSLAB/30-09-22 $

*/