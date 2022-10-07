/*
    NAME : Shresth Sonkar 
    REGNO : 20214272
*/

#include <stdio.h>
#include <math.h>

void ByVal(int x, int y)
{
    x++; 
    y++;
}

void ByRef(int *x, int *y)
{
    (*x)++; 
    (*y)++;
}

int main()
{
    int a=7, b=9;
    
    ByVal(a, b);
    printf("(VAL)\na+b = %d+%d = %d\n", a, b, a+b);
    
    ByRef(&a, &b);
    printf("\n(REF)\na+b = %d+%d = %d\n", a, b, a+b);
}

/* OUTPUTS

~/desktop/cse/ASSGN/09-09-22 $ clang Q2.c -o g2
~/desktop/cse/ASSGN/09-09-22 $ ./q2
(VAL)
a+b = 7+9 = 16

(REF)
a+b = 8+10 = 18
~/desktop/cse/ASSGN/09-09-22 $

*/