// Shresth Sonkar
// 20214272
// Q4

#include <stdio.h>

int top1 = -1;
int top2 = 0;
int s=0;

void setSize(int size)
{
    s = size;
    top2 = s;
}

void push1(int stck[], int x)
{
    if(top1 < top2 - 1)
        stck[++top1] = x;
    else
        printf("Stack Overflow\n");
}

void push2(int stck[], int x)
{
    if(top1 < top2 - 1)
        stck[--top2] = x;
    else
        printf("Stack Overflow\n");
}

int pop1(int stck[])
{
    if(top1 >= 0)
    {
        int ele = stck[top1--];
        return ele;
    }
    else
    {
        printf("Stack Underflow\n");
        return -1;
    }
}

int pop2(int stck[])
{
    if(top2 < s)
    {
        int ele = stck[top2++];
        return ele;
    }
    else
    {
        printf("Stack Underflow\n");
        return -1;
    }
}

void prntStck1(int stck[])
{
    if(top1 == -1)
    {
        printf("\n");
        return ;
    }
    int ele = pop1(stck);
    printf("%d, ", ele);
    prntStck1(stck);
    push1(stck, ele);
}

void prntStck2(int stck[])
{
    if(top2 == s)
    {
        printf("\n");
        return ;
    }
    int ele = pop2(stck);
    printf("%d, ", ele);
    prntStck2(stck);
    push2(stck, ele);
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
        if(i%2 == 0)
            push2(stck, i);
        else
            push1(stck, i);
    }

    printf("\nStack 1 : ");
    prntStck1(stck);
    printf("\nStack 2 : ");
    prntStck2(stck);

    printf("\nPopping : \n");
    for(int i=0; i<=size/2; i++)
    {
        if(i%2 == 0)
            printf("%d\n", pop2(stck));
        else
            printf("%d\n", pop1(stck));
    }

    printf("\nStack 1 : ");
    prntStck1(stck);
    printf("\nStack 2 : ");
    prntStck2(stck);

    return 0;
}

/* OUTPUTS

~/desktop/cse/ASSGN/DSLAB/30-09-22 $ clang Q4.c -o q4
~/desktop/cse/ASSGN/DSLAB/30-09-22 $ ./q4            
Enter size of stack : 10

Stack 1 : 9, 7, 5, 3, 1, 

Stack 2 : 8, 6, 4, 2, 0, 

Popping : 
8
9
6
7
4
5

Stack 1 : 3, 1, 

Stack 2 : 2, 0, 
~/desktop/cse/ASSGN/DSLAB/30-09-22 $

*/