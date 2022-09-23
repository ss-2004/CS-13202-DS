// Shresth Sonkar
// 20214272
// Q3

#include <stdio.h>

void swp(int *x, int *y)
{
	int t=*x;
	*x = *y;
	*y = t;
}

void bSort(int a[], int n)
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(a[j+1] < a[j])
				swp(&a[j], &a[j+1]);		
		}		
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
	bSort(arr, n);
	for(i=0; i<n; i++)
		printf("%d, ", arr[i]);
	printf("\n");

	return 0;
}

/* OUTPUTS 

~/20214272/DSLAB/23-09-22 $ gcc Q3.c -o q3
~/20214272/DSLAB/23-09-22 $ ./q3
Enter size : 6
Enter array : 9 3 7 6 4 8

Sorted : 3, 4, 6, 7, 8, 9,
~/20214272/DSLAB/23-09-22 $

*/
