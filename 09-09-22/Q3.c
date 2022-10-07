/*
    NAME : Shresth Sonkar 
    REGNO : 20214272
*/

#include <stdio.h>
#include <math.h>

void ByRef(int *x, int *y)
{
    (*x) = (*x)-(*y); 
    (*y) = (*x)+(*y);
    (*x) = (*y)-(*x);
}

int main()
{
    int a=7, b=9;
    
    printf("a=%d b=%d\n", a, b);
    a = a-b; 
    b = a+b;
    a = b-a;
    printf("(VAL)\na=%d b=%d\n\nRE-SETTING...\n", a, b);
    
    a=7; b=9; // reset

    printf("\na=%d b=%d\n", a, b);
    a = a^b; 
    b = a^b;
    a = b^a;
    printf("(XOR)\na=%d b=%d\n\nRE-SETTING...\n", a, b);
    
    a=7; b=9; // reset

    printf("\na=%d b=%d\n", a, b);
    ByRef(&a, &b);
    printf("(REF)\na=%d b=%d\n", a, b);
}

/* OUTPUTS

~/desktop/cse/ASSGN/09-09-22 $ clang Q3.c -o q3
~/desktop/cse/ASSGN/09-09-22 $ ./q3
a=7 b=9
(VAL)
a=9 b=7

RE-SETTING...

a=7 b=9
(XOR)
a=9 b=7

RE-SETTING...

a=7 b=9
(REF)
a=9 b=7
~/desktop/cse/ASSGN/09-09-22 $

*/