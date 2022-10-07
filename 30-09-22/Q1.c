// Shresth Sonkar
// 20214272
// Q1

#include <stdio.h>

int top = -1;
int s=0;

void setSize(int size)
{
    s = size;
}

void push(int stck[], int x)
{
    if(top != s-1)
        stck[++top] = x;
    else
        printf("Stack Overflow\n");
}

int pop(int stck[])
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int ele = stck[top--];
        return ele;
    }
}

void prntStck(int stck[])
{
    if(top == -1)
    {
        printf("\n");
        return ;
    }
    int ele = pop(stck);
    printf("%d, ", ele);
    prntStck(stck);
    push(stck, ele);
}

int main()
{
    int in, size=5;
    printf("Enter size of stack : ");
    scanf("%d", &size);
    setSize(size);

    int stck[size];
    for(int i=0; i<size; i++)
    {
        scanf("%d", &in);
        push(stck, in);
    }

    prntStck(stck);

    pop(stck);
    push(stck, -45);
    prntStck(stck);

    return 0;
}

/* OUTPUTS

~/desktop/cse/ASSGN/DSLAB/30-09-22 $ clang Q1.c -o q1
~/desktop/cse/ASSGN/DSLAB/30-09-22 $ ./q1            
Enter size of stack : 5
1 2 3 4 5
5, 4, 3, 2, 1, 
-45, 4, 3, 2, 1, 
~/desktop/cse/ASSGN/DSLAB/30-09-22 $

*/
