// Shresth Sonkar
// 20214272
// Q2a

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack* createStack(unsigned size);
int isEmpty(struct Stack* stack);
int isOperand(char ch);
int precOf(char ch);
int inToPost(char* str);
 
void push(struct Stack* stack, char op);
char pop(struct Stack* stack);
char peek(struct Stack* stack);

struct Stack 
{
    int top;
    unsigned size;
    int* arr;
};

struct Stack* createStack(unsigned size)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack)
        return NULL;

    stack->top = -1;
    stack->size = size;
    stack->arr = (int*)malloc(stack->size * sizeof(int));
 
    return stack;
}
 
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precOf(char ch)
{
    switch (ch) 
    {
        case '+':
        case '-':
            return 1;
    
        case '*':
        case '/':
            return 2;
    
        case '^':
            return 3;
    }
    return -1;
}
 
char peek(struct Stack* stack)
{
    return stack->arr[stack->top];
}
 
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->arr[stack->top--];
    return '$';
}
 
void push(struct Stack* stack, char op)
{
    stack->arr[++stack->top] = op;
}

int inToPost(char* str)
{
    int i, k;
    struct Stack* stack = createStack(strlen(str));
    if(!stack)
        return -1;
 
    for(i=0, k=-1; str[i]; ++i) 
    {
        if (isOperand(str[i]))
            str[++k] = str[i];
        else if (str[i] == '(')
            push(stack, str[i]);
        else if (str[i] == ')') 
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                str[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1;
            else
                pop(stack);
        }
        else
        {
            while(!isEmpty(stack) && precOf(str[i]) <= precOf(peek(stack)))
                str[++k] = pop(stack);
            push(stack, str[i]);
        }
    }

    while (!isEmpty(stack))
        str[++k] = pop(stack);
    str[++k] = '\0';
    printf("Postfix : %s\n", str);
    return 0;
}
 
int main()
{
    printf("Enter Infix : ");
    char str[32];
    scanf("%[^\n]%*c", str);
    inToPost(str);
    return 0;
}

/* OUTPUTS

~/desktop/cse/ASSGN/DSLAB/30-09-22 $ clang Q2a.c -o q2a
~/desktop/cse/ASSGN/DSLAB/30-09-22 $ ./q2a
Enter Infix : (A-B/C)*(D/E-F)
Postfix : ABC/-DE/F-*
~/desktop/cse/ASSGN/DSLAB/30-09-22 $

*/