// Shresth Sonkar
// 20214272
// Q2

#include <stdio.h>

int main()
{	
	int i, j, n, t, dup=0, c=0;
	printf("Enter size of array : ");
	scanf("%d", &n);
	int arr[n];
	
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);

	for(i=0; i<n; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				t = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = t;
			}
		}
	}			

	for(i=0; i<n-1; i++)
	{
		j=i;
		while(arr[j] == arr[j+1])
		{
			c++;
			j++;
		}
		if(c>0)
		{
			dup++;
			c=0;	
		}
		i=j;
	}

	printf("Duplicate elements = %d\n", dup);
	
	return 0;
}

/* OUTPUTS : 

 > ~/20214272/DS/16-09-22 $ gcc Q2.c -o q2
 > ~/20214272/DS/16-09-22 $ ./q2
Enter size of array : 6
1
2
3
1
2
4
Duplicate elements = 2
 > ~/20214272/DS/16-09-22 $ ./q2
Enter size of array : 3
1
2
3
Duplicate elements = 0
 > ~/20214272/DS/16-09-22 $ 


*/
