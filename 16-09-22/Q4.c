// Shresth Sonkar
// 20214272
// Q4

#include <stdio.h>

int main()
{
     int i, j, n=0, t, curr, c=0;
        
	printf("Enter size : ");
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
	
	for(i=0; i<n; i++)
	{
		curr = arr[i];
		j=i;
		while(curr == arr[j])
		{
			c++;
		}	
		printf("Frequency of %d = %d\n", curr, c);
		c=0;
		i=j;
	}
	
	return 0;
}
