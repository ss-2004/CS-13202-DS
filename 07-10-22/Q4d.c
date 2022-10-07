// Shresth Sonkar
// 20214272
// Q4d

#include <stdio.h>

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
	
	return 0;
}

/* OUTPUTS

~/20214272/DS/07-10-22 $ gcc Q4d.c -o q4d
~/20214272/DS/07-10-22 $ ./q4d
(VAL)
a+b = 7+9 = 16

(REF)
a+b = 8+10 = 18
~/20214272/DS/07-10-22 $

*/

