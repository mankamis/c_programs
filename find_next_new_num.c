/*
 *  ------------------------------------------------------------------
 *  
 *  find_next_new_num.c
 *  Question: find next number using same set of digit. 
 *  for example if input is 3425 so output would be 3452
 *
 *  Jan 2017, Mankamana Mishra
 * 
 * Copyright (c) 2017 by Mankamana Mishra.
 * All rights reserved.
 *------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int power_of (int num, int base)
{
    int i = 0;
    int result = 1;
    for (i = 0; i<num; i++) {
        result = result * base; 
    }
    return result;
}
/*
 * swap_digit API would swap digit in given number. 
 *
 * Input: 
 * num:      number where operation is to be performed. 
 * h_digit : Higher order digit
 * h_index : Higher order index where h_digit is present
 * l_digit : Lower  order digit
 * l_index : Lower  order index where l_digit is present
 *
 * for Example:
 * 345495654 if we want to swap 2nd and 4th digit (starting count from 0)
 * 876543210  >>>>>>>>> index
 * h_digit : 9
 * h_index : 4
 * l_digit : 6
 * l_index : 2
 *
 * Expected output: 345465954
 *
 * Output: 
 * number with swaped digit
 *
 * Assumption: num has enough digit to accomodate h_index and l_index
 */
int swap_digit (int num, int h_digit, int h_index, int l_digit, int l_index) 
{
    /*
     * if High index is less than or equal to Low index, return error 
     */
    if (h_index <  l_index  ){
        printf ("\n Index are not correct. return the input number as is\n");
        return num;
    }

    /*
     *  to swap the digits in number, first we can remove the place value 
     *  of both digit from original value. later we can add new place value 
     *  for both digit. it should give us number after swaping the digits.
     */
    num = num - (power_of (h_index , 10)* h_digit) - 
                (power_of (l_index, 10) * l_digit);

    num = num + ((power_of (h_index , 10)* l_digit) + 
                ((power_of (l_index, 10) * h_digit)));
    return (num);
}
int main ()
{
    int num = 345495654; 
    num = swap_digit (num, 9, 4, 6,2);
    printf ("\n Number after swap = %d\n", num);
}



#if 0
                                    UNIT TEST
------------------------------------------------------------------------------

------------------------------------------------------------------------------
#endif 
