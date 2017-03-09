/*
 *Sum all the numbers of the array (in F# and Haskell you get a list) 
 *except the highest and the lowest element (the value, not the index!).
 *(The highest/lowest element is respectively only one element at each edge, 
 *even if there are more than one with the same value!)
 * Example:
 *
 *{ 6, 2, 1, 8, 10 } => 16
 *{ 1, 1, 11, 2, 3 } => 6
 *
 * If array is empty, null or None, or if only 1 Element exists, return 0.
 * Note:In C++ instead null an empty vector is used. 
 * In C there is no null. ;-) 
 */
#include <stdio.h>
#include <stdlib.h>
int sum(int* numbers, int numbersCount)
{
    if (numbers == NULL) {
        return 0;
    }
    int num_of_elements = numbersCount;
    printf ("\n num_of_elements = %d\n", num_of_elements);
    if (num_of_elements == 1) {
        return 0;
    }

    int sum = 0;
    int i = 0;
    int low = numbers [i], high = numbers [i];

    for (i = 0; i < num_of_elements ; i++) {
        if (numbers[i] < low) {
            low = numbers[i];
        } else if (numbers[i] > high) {
            high = numbers[i];
        }
        sum += numbers[i];

    }
    printf ("\n low = %d, high = %d\n", low, high);
    sum = sum - low - high;
    return sum;
}
int main ()
{
    int a[] = {6, 2, 1, 8, 10};
    int sum_without = sum (a, 5);
    printf ("\n sum = %d\n", sum_without);
}
