// Shresth Sonkar
// 20214272
// Q2

#include <stdio.h>

void swp(int *x, int *y)
{
	int t=*x;
	*x = *y;
	*y = t;
}

void sSort(int a[], int n)
{
	int i, j, min;
	for(i=0; i<n-1; i++)
	{
		min = i;
		for(j=i; j<n; j++)
		{
			if(a[j] < a[min])
				min = j;
		}		
		swp(&a[i], &a[min]);
	}
}

int main()
{
	int n, i;
	printf("Enter size : ");
	scanf("%d", &n);
	int arr[n];
	
	printf("Enter array : ");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);

	printf("\nSorted : ");
	sSort(arr, n);
	for(i=0; i<n; i++)
		printf("%d, ", arr[i]);
	printf("\n");

	return 0;
}

/* OUTPUTS 

~/20214272/DSLAB/23-09-22 $ gcc Q1.c -o q1
~/20214272/DSLAB/23-09-22 $ ./q1
Enter size : 4
Enter array : 4 8 6 1

Sorted : 1, 4, 6, 8, 
~/20214272/DSLAB/23-09-22 $

*/

