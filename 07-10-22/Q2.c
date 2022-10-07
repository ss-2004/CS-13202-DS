// Shresth Sonkar
// 20214272
// Q2

#include <stdio.h>
#include <string.h>

int top=-1;
int s=0;
char stack[32];

void setSize(int size)
{
	s = size;
	stack[size];
}

void push(char ch)
{
	if(top != s-1)
		stack[++top] = ch;
	else
		printf("STACKOVERFLOW!\n");
}

char pop()
{
	if(top == -1)
	{
		printf("STACKUNDERFLOW!");
		return '!';
	}
	else
	{
		char ch = stack[top--];
		return ch;
	}
}

void revStr(char* str, int n)
{
	int i;
	for(i=0; i<n; i++)
		push(str[i]);
	for(i=0; i<n; i++)
		str[i] = pop();
}

int main()
{
	char str[32];
	printf("Enter a string : ");
	scanf("%[^\n]%*c", str);
	setSize(strlen(str));
	revStr(str, strlen(str));
	printf("Reverse : %s\n", str);
	
	return 0;
}

/* OUTPUTS

~/20214272/DS/07-10-22 $ gcc Q2.c -o q2
~/20214272/DS/07-10-22 $ ./q2
Enter a string : hello world
Reverse : dlrow olleh
~/20214272/DS/07-10-22 $ ./q2
Enter a string : racecar
Reverse : racecar
~/20214272/DS/07-10-22 $

*/

