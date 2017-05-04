/*
 *In a small town the population is p0 = 1000 at the beginning of a year. 
 *The population regularly increases by 2 percent per year and moreover 50 
 *new inhabitants per year come to live in the town. 
 *How many years does the town need to see its population 
 *greater or equal to p = 1200 inhabitants?
 */

#include <stdio.h>
#include <stdlib.h>

int nbYear(int p0, double percent, int aug, int p) 
{
    int num_of_year = 0;
    int population = p0;
    int growth = 0 ;

    while (population < p) {
        growth = (int)population * (percent / 100);
        printf ("\n Growth = %d\n", growth); 

        population = population + growth + aug ;  
        num_of_year ++;
    }
    return num_of_year;
}

int main ()
{
    int num = 0;
    num = nbYear (1000, 2, 50, 1200);
    printf ("\n num = %d\n", num);
}
