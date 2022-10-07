// Shresth Sonkar
// 20214272
// Q2c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define l 32

void input();
void push(char c);
char pop();
int isOperator(char x);
void rev(char str[]);
void post2in();

char str[l], stack[l];
int top = -1;

void input()
{
    printf("Postfix : ");
    scanf("%[^\n]%*c", str);
}

void push(char ch)
{
    stack[++top] = ch;
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

void rev(char str[])
{
    int n = strlen(str);
    char ch;
    for(int i=0; i<n/2; i++)
    {
        ch = str[i];
        if(ch != '(' && ch != ')')
        {
            str[i] = str[n-i-1];
            str[n-i-1] = ch;
        }
        else
        {
            if(ch == '(')
            {
                str[i] = '(';
                str[n-i-1] = ')';
            }
            else
            {
                str[i] = ')';
                str[n-i-1] = '(';
            }
        }
    }
}

void post2in()
{
    int n, i, j=0;
    char a, b, op, t[l];
    rev(str);
    n=strlen(str);
    
    for(i=0;i<l;i++)
        stack[i]='\0';
    printf("Infix : ");
    
    for(i=0;i<n;i++)
    {
        if(isOperator(str[i]))
            push(str[i]);
        else
        {
            t[j++]=str[i];
            t[j++]=pop();
        }
    }
    
    t[j]=str[top--];
    rev(t);
    puts(t);
}

int main()
{
    input();
    post2in();
    return 0;
}

/* OUTPUTS

~/desktop/cse/ASSGN/DSLAB/30-09-22 $ clang Q2c.c -o q2c
~/desktop/cse/ASSGN/DSLAB/30-09-22 $ ./q2c             
Enter Postfix : ABC/-DE/F-*              
Infix : A-B/C*D/E-F
~/desktop/cse/ASSGN/DSLAB/30-09-22 $

*/