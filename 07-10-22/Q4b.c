// Shresth Sonkar
// 20214272
// Q4b

#include <stdio.h>
#include <string.h>

int isVowel(char ch)
{
	switch(ch)
	{
		case 'a' :
		case 'e' :
		case 'i' :
		case 'o' :
		case 'u' :
		case 'A' :
		case 'E' :
		case 'I' :
		case 'O' :
		case 'U' :
			return 1;
		default : 
			return 0;
	}
}

void count(char* str, int n)
{
	char t;
	char* p = &str[0];
	int i, v=0, c=0;
	
	for(i=0; i<n; i++)
	{
		if(isVowel(*(p+i)))
			v++;
		else
			c++;
	}
	
	printf("VOWELS : %d\nCONSONANTS : %d\n", v, c);
}

int main()
{
	char str[32];
	printf("Enter a string : ");
	scanf("%[^\n]%*c", str);
	count(str, strlen(str));
	
	return 0;
}

/* OUTPUTS

~/20214272/DS/07-10-22 $ gcc Q4b.c -o q4b
~/20214272/DS/07-10-22 $ ./q4b
Enter a string : hello
VOWELS : 2
CONSONANTS : 3
~/20214272/DS/07-10-22 $ ./q4b
Enter a string : world
VOWELS : 1
CONSONANTS : 4
~/20214272/DS/07-10-22 $

*/

