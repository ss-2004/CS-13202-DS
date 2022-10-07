// Shresth Sonkar
// 20214272
// Q4a

#include <stdio.h>
#include <string.h>

void revStr(char* str, int n)
{
	char t;
	char* start = &str[0];
	char* end = &str[n-1];
	int i;
	
	for(i=0; i<n/2; i++)
	{
		t = *end;
		*end = *start;
		*start = t;
		
		start++;
		end--;
	}
}

int main()
{
	char str[32];
	printf("Enter a string : ");
	scanf("%[^\n]%*c", str);
	revStr(str, strlen(str));
	printf("Reverse : %s\n", str);
	
	return 0;
}

/* OUTPUTS

~/20214272/DS/07-10-22 $ gcc Q4a.c -o q4a
~/20214272/DS/07-10-22 $ ./q4a
Enter a string : hello 
Reverse : olleh
~/20214272/DS/07-10-22 $ ./q4a
Enter a string : racecar
Reverse : racecar
~/20214272/DS/07-10-22 $

*/

