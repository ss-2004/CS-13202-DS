// Shresth Sonkar
// 20214272
// Q4c

#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int n;
	int* ptr = (int*)malloc(sizeof(n));
	
	if(ptr != NULL)
		printf("%dB Memory allocated at : %X\n", sizeof(n), ptr);
	else
		printf("Memory allocation failed!\n");
		
	free(ptr);
	printf("%dB Memory deallocated from : %X\n", sizeof(n), ptr);
	
	return 0;
}

/* OUTPUTS

~/20214272/DS/07-10-22 $ gcc Q4e.c -o q4e
~/20214272/DS/07-10-22 $ ./q4e
4B Memory allocated at : 1E41010
4B Memory deallocated from : 1E41010
~/20214272/DS/07-10-22 $ 

*/

