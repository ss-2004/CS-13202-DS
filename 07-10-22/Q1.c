// Shresth Sonkar
// 20214272
// Q1

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int q[SIZE];
int r = -1;
int f = -1;

void enqueue()
{
    int x;
    if (r == SIZE - 1)
        printf("Overflow \n");
    else
    {
        if (f == -1)

            f = 0;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &x);
        r = r + 1;
        q[r] = x;
    }
}

int dequeue()
{
    if (f == -1 || f > r)
    {
        printf("Underflow \n");
        return -1;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", q[f]);
        f = f + 1;
        return 1;
    }
}

void show()
{

    if (f == -1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = f; i <= r; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        enqueue();
    }

    dequeue();
    dequeue();
    show();

    return 0;
}

/* OUTPUTS

 ➜ ~/desktop/cse/ASSGN/DSLAB/07-10-22 $ ./q1
Element to be inserted in the Queue
 : 1
Element to be inserted in the Queue
 : 2
Element to be inserted in the Queue
 : 3
Element to be inserted in the Queue
 : 4
Element to be inserted in the Queue
 : 5
Element deleted from the Queue: 1
Element deleted from the Queue: 2
Queue: 
3 4 5 
 ➜ ~/desktop/cse/ASSGN/DSLAB/07-10-22 $

*/
