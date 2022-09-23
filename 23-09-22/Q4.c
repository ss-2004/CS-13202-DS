// Shresth Sonkar
// 20214272
// Q4

#include <stdio.h>

int n;

int input()
{
	printf("Enter side of square : ");
	scanf("%d", &n);
	return n; 
}

void display(int a[n][n])
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%d\t", a[i][j]);
		printf("\n"); 
	}
}

int isOutOfBounds(int i, int j)
{
	if(i<0 || i>n-1 || j<0 || j>n-1)
		return 1;
	else
		return 0;
}

int isOccupied(int a[n][n], int i, int j)
{
	if(1 <= a[i][j] && a[i][j] <= n*n)
		return 1;
	else 
		return 0;
}

void fill(int a[n][n])
{
	int i=n/2, j=n-1, c=1;
	while(c <= n*n)
	{
		if(isOutOfBounds(i,j))
		{
			if(i==-1 && j==n)
			{	
				j = n-2;
				i = 0;
			}
			else
			{
				if(j==n)
					j = 0;
				else if(i<0)	
					i = n-1;				
			}
		}
		else if(isOccupied(a,i,j))
		{
			j -= 2;
			i++;
		}
		else
		{
			a[i][j] = c++;
			i--;
			j++;
		}
	} 
}

int main()
{
	int i, j, n = input();
	int arr[n][n];
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			arr[i][j] = -1; 
	}
	fill(arr);
	display(arr);
	return 0;
}

/* OUTPUTS

~/20214272/DSLAB/23-09-22 $ gcc Q4.c -o q4
~/20214272/DSLAB/23-09-22 $ ./q4
Enter side of square : 3
2	7	6	
9	5	1	
4	3	8	
~/20214272/DSLAB/23-09-22 $ ./q4
Enter side of square : 5
9	3	22	16	15	
2	21	20	14	8	
25	19	13	7	1	
18	12	6	5	24	
11	10	4	23	17	
~/20214272/DSLAB/23-09-22 $

*/
