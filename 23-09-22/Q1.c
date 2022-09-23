// Shresth Sonkar
// 20214272
// Q1

#include <stdio.h>

void iSort(int a[], int n)
{
	int i, j, t, curr;
	for(i=1; i<n; i++)
	{
		curr = a[i];
		t = i;
		while(t > 0 && a[t-1] > curr)
		{
			a[t] = a[t-1];
			t = t-1;
		}		
		a[t] = curr;
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
	iSort(arr, n);
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
