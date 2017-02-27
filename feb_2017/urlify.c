/*
 *  ------------------------------------------------------------------
 *  
 * urlify.c
 * Book: Cracking the coding interview
 * Question: Write a method to replace all space in a string with '%20'.
 * you may assume that the string has sufficient space at the end to hold 
 * additional char and that you are given the true length of string. 
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
#include "utility.h"

/*
 *  This API is brute force method. 
 * Time complexity  O(n)
 * Space complexity O(n)
 */
char * replace_blanck_space_brute_force_method (char *str, int len) 
{

    printf ("\n %s(): Start string = %s len = %d",
            __FUNCTION__, str, len);
    if (str == NULL) {
        printf ("\nBlanck string. No operation needed \n");
    }

    /*
     * Create new string, memset to 0 and setup NULL char at end
     */
    char *str_new = malloc (sizeof (char) * (len+1));
    memset (str_new, 0, (sizeof(char) * (len + 1)));
    str_new [len+1] = '\0';

    int index = 0, new_index = 0, is_space = FALSE;

    for (index = 0; index < len; index ++) {

        /*
         * If char is not blanck space and space flag is not set. copy 
         * it as it is to new string.
         */
        if (str[index] != ' ' && (!is_space)) {
            str_new[new_index ++] = str [index];
        } 

        /*
         * If blank space is there, setup the flag
         */
        if (str[index] == ' ') {
            is_space = TRUE;
            continue;
        }

        /*
         * if space flag is set. it means we had hit blanck space earlier
         * and now we have got not End of String & non blank space char.
         * so now we have to fill %20 in new string . make sure you release 
         * the flag so that it would be reused. 
         */
        if ((str[index] != ' ') && (is_space) && (str[index] != '\0')) {
            str_new[new_index ++] = '%';
            str_new[new_index ++] = '2';
            str_new[new_index ++] = '0';
            str_new[new_index ++] = str[index];
            is_space = FALSE;

        }
    }
    return str_new;
}

int main ()
{
    char str1[] = "      a    b     c        ";
    char *str = NULL;
    clock_t begin = clock();
    str = replace_blanck_space_brute_force_method (str1, strlen(str1));
    clock_t end = clock();
    double time_spent_1 = (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("\n Time spent for API is_unique = %f\n", time_spent_1);
    printf ("\n STRING IS  = %s Len = %lu\n\n", str, strlen (str));

    return 1;
}



#if 0
                                    UNIT TEST
------------------------------------------------------------------------------
MANKAMIS-M-K0FG:feb_2017 mankamis$ gcc urlify.c
MANKAMIS-M-K0FG:feb_2017 mankamis$ ./a.out

 replace_blanck_space_brute_force_method(): Start string =  
                                            a    b     c         len = 26
 Time spent for API is_unique = 0.000046

STRING IS  = %20a%20b%20c Len = 12

MANKAMIS-M-K0FG:feb_2017 mankamis$

------------------------------------------------------------------------------
#endif 
