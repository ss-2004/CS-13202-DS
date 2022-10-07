// Shresth Sonkar
// 20214272
// Q4g

#include <stdio.h>
#include <stdlib.h>

struct car
{
    int year;
    int odo;
    char fuel;
};

struct car* setInfo()
{
    struct car *ptr = (struct car *)malloc(sizeof(struct car));
    ptr->year = 1989;
    ptr->odo = 69420;
    ptr->fuel = 'P';

    return ptr;
}

int main()
{
    struct car* ptr = setInfo();
    printf("Year : %d\n", (ptr->year));
    printf("Odometer : %dkm\n", (ptr->odo));
    printf("Fuel type : %c\n", (ptr->fuel));

    return 0;
}

/* OUTPUTS

 ➜ ~/desktop/cse/ASSGN/DSLAB/07-10-22 $ clang Q4g.c -o q4g
 ➜ ~/desktop/cse/ASSGN/DSLAB/07-10-22 $ ./q4g
Year : 1989
Odometer : 69420km
Fuel type : P
 ➜ ~/desktop/cse/ASSGN/DSLAB/07-10-22 $

*/
