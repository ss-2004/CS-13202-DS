// Shresth Sonkar
// 32214272
// Q2e

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define l 32

void input();
void push(char c);
char pop();
int isOperator(char x);
void pre2in();

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

void pre2in()
{
    int n, i;
    char a, b, op;
    n = strlen(str);

    for(i=0; i<l; i++)
        stack[i] = '\0';
    printf("Infix : ");

    for(i=0; i<n; i++)
    {
        if(isOperator(str[i]))
            push(str[i]);
        else
        {
            op = pop();
            a = str[i];
            printf("%c%c", a, op);
        }
    }

    printf("%c\n", str[top--]);
}

int main()
{
    input();
    pre2in();
    return 0;
}

/* OUTPUTS

~/desktop/cse/ASSGN/DSLAB/30-09-22 $ clang Q2e.c -o q2e
~/desktop/cse/ASSGN/DSLAB/30-09-22 $ ./q2e             
Prefix : *-A/BC-/DEF
Infix : A-B/C*D/E-F
~/desktop/cse/ASSGN/DSLAB/30-09-22 $

*/