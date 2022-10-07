// Shresth Sonkar
// 20214272
// Q4c

#include <stdio.h>

int main()
{
	char c;
	char* pc = &c;
	printf("Char : %d\n", sizeof(*pc));
	
	short s;
	short* ps = &s;
	printf("Short : %d\n", sizeof(*ps));
	
	int i;
	int* pi = &i;
	printf("Int : %d\n", sizeof(*pi));
	
	long l;
	long* pl = &l;
	printf("Long : %d\n", sizeof(*pl)); 

	float f;
	float* pf = &f;
	printf("Float : %d\n", sizeof(*pf));
	
	double d;
	double* pd = &d;
	printf("Double : %d\n", sizeof(*pd));	
	
	return 0;
}

/* OUTPUTS

~/20214272/DS/07-10-22 $ gcc Q4c.c -o q4c
~/20214272/DS/07-10-22 $ ./q4c
Char : 1
Short : 2
Int : 4
Long : 8
Float : 4
Double : 8
~/20214272/DS/07-10-22 $

*/

