// Shresth Sonkar
// 20214272
// Q3

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
 
    if(!stack) return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
 
    if(!stack->array) return NULL;
 
    return stack;
}
 
int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
 
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
 
char pop(struct Stack* stack)
{
    if(!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
 
void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}

int eval(char* str)
{
    struct Stack* stack = createStack(strlen(str));
    int i;
 
    if(!stack) return -1;
 
    for (i = 0; str[i]; ++i)
    {
        if(isdigit(str[i]))
            push(stack, str[i] - '0');
        else
        {
            int n1 = pop(stack);
            int n2 = pop(stack);
            switch(str[i])
            {
            case '+': push(stack, n2 + n1); break;
            case '-': push(stack, n2 - n1); break;
            case '*': push(stack, n2 * n1); break;
            case '/': push(stack, n2/n1); break;
            }
        }
    }
    return pop(stack);
}
 
int main()
{
    printf("Enter Postfix : ");
    char str[32];
    scanf("%[^\n]%*c", str);
    printf("Answer : %d\n", eval(str));
    return 0;
}

/* OUTPUTS

~/desktop/cse/ASSGN/DSLAB/30-09-22 $ clang Q3.c -o q3
~/desktop/cse/ASSGN/DSLAB/30-09-22 $ ./q3
Enter Postfix : 241*+8-        
Answer : -2
~/desktop/cse/ASSGN/DSLAB/30-09-22 $

*/