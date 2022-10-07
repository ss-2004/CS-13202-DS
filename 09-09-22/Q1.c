/*
    NAME : Shresth Sonkar 
    REGNO : 20214272
*/

#include <stdio.h>

int mn(int a, int b)
{
    return (a<b?a:b);
}

int mx(int a, int b)
{
    return (a>b?a:b);
}

long int fac(int n)
{
    if(n==1) return 1;
    else return n*fac(n-1);
}

int fibo(int n)
{
    if(n==1 || n==2)
        return 1;
    else return ( fibo(n-1) + fibo(n-2) );
}

int hcf(int a, int b)
{
    if(mx(a,b) % mn(a,b)==0) 
    return mn(a,b);
    else return hcf(mn(a,b), mx(a,b)%mn(a,b));
}

int linS(int arr[], int lo, int hi, int key)
{
    if(lo == hi) 
        return -1;
    else if(arr[lo] == key)
        return lo;
    else return linS(arr, lo+1, hi, key);
}

int binS(int arr[], int lo, int hi, int key)
{
    int mid = (lo+hi)/2;
    if(hi<lo)
        return -1;
    else if(arr[mid] > key)
        return binS(arr, lo, mid, key);
    else if(arr[mid] < key)
        return binS(arr, mid, hi, key);
    else
        return mid;
}

int main()
{
    int a=12, b=10, key=5;
    int arr[] = {-9, -2, 1, 3, 5, 8};
    printf("%d! is %ld\n", key, fac(key));
    printf("Fibonacci number at %d is %d\n", key, fibo(key));
    printf("HCF of %d & %d is %d\n", a, b, hcf(a,b));
    printf("Key %d is at %d\n", key, binS(arr, 0, 6, key));
    printf("Key %d is at %d\n", key, linS(arr, 0, 6, key));
}

/* OUTPUTS : 

~/desktop/cse/ASSGN/09-09-22 $ clang Q1.c -o q1
~/desktop/cse/ASSGN/09-09-22 $ ./q1
5! is 120
Fibonacci number at 5 is 5
HCF of 12 & 10 is 2
Key 5 is at 4
Key 5 is at 4
~/desktop/cse/ASSGN/09-09-22 $

*/
