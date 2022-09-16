// Shresth Sonkar
// 20214272
// Q6

#include <stdio.h>

int main()
{
	int i, j, n=3;
	int arr[3][3];
	printf("Enter array : \n");
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			scanf("%d", &arr[i][j]);
	}
	
	printf("Upper Triangular : \n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<i; j++)
			printf("  ");
		for(j=i; j<n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("Lower Triangular : \n");
	for(i=0; i<n; i++)
        {
                for(j=0; j<=i; j++)
                        printf("%d ", arr[i][j]);
		printf("\n");
        }

	return 0;
}

/* OUTPUTS : 

 > ~/20214272/DS/16-09-22 $ gcc Q6.c -o q6
 > ~/20214272/DS/16-09-22 $ ./q6
Enter array : 
1 2 3 
4 5 6
7 8 9
Upper Triangular : 
1 2 3 
  5 6 
    9 
Lower Triangular : 
1 
4 5 
7 8 9
 > ~/20214272/DS/16-09-22 $ ./q6
Enter array : 
1 1 1 
2 2 2 
3 3 3
Upper Triangular : 
1 1 1 
  2 2 
    3 
Lower Triangular : 
1 
2 2 
3 3 3

*/
