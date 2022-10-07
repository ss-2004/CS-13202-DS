// Shresth Sonkar
// 20214272
// Q4f

#include <stdio.h>
#include <stdlib.h>

struct car
{
    int year;
    int odo;
    char fuel;
};

void setInfo(struct car *ptr)
{
    ptr->year = 1989;
    ptr->odo = 69420;
    ptr->fuel = 'P';
}

void printInfo(struct car *ptr)
{
    printf("Year : %d\n", (ptr->year));
    printf("Odometer : %dkm\n", (ptr->odo));
    printf("Fuel type : %c\n", (ptr->fuel));
}

int main()
{
    struct car R32;
    struct car *p = (struct car *)malloc(sizeof(struct car));
    
    setInfo(p);
    printInfo(p);

    return 0;
}

/* OUTPUTS

➜ ~/desktop/cse/ASSGN/DSLAB/07-10-22 $ ./q4f
Year : 1989
Odometer : 69420km
Fuel type : P
 ➜ ~/desktop/cse/ASSGN/DSLAB/07-10-22 $
 
 */
