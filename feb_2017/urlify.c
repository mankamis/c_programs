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

#define MAX 3 /* Max char to fill. in this case its %20 which is 3*/

/*
 *  This API is brute force method. 
 * Time complexity  O(n)
 * Space complexity O(n)
 */
char * replace_blanck_space_brute_force_method (char *str, int len) 
{

    if (str == NULL) {
        printf ("\nBlanck string. No operation needed \n");
        return NULL;
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

/*
 * Assumption : string has enough space in last to fit char. 
 *
 * API NOT WORKING AS OF NOW 
 */
void string_replace_by_api (char *str, int len) 
{
    if (str == NULL || len == 0) {
        printf ("\n Invalid string\n");
        return;
    }

    int index = 0; 
    int temp_index_1 = 0; 
    int temp_index_2 = 0; 
    int count = 0;
    int is_space_flag = FALSE;
    int last_processed_index = 0;

    for (index = 0; index < len; index ++) {

        /*
         * if reached end of string. return. no need to process further.
         */
        if (str[index] == '\0') {
            printf ("\n Hitting END\n");
            return;
        }
        /*
         * if we are having not blank space char and flag is off it means
         * we do not have previously blank space . keep going
         */
        if ((str[index] != ' ') && (!is_space_flag)) {
            continue;
        }

        /*
         * if we have hit blank space, set the flag. start count. we need to 
         * check how many blank space are there before we hit next char. 
         * if we hit end of string, no need to process. 
         */
        if (str[index] == ' ') {
            is_space_flag = TRUE;
            count ++;
        }

        /*
         * If we have hit non space char and previous space flag is set.
         * it means after count number of blank space we have hit new char.
         * now in all of the blank space we need to fill %20. but there are 
         * 3 case to be considered with respect to shifting elements.  
         * 1 -  If count of blank space is == MAX 
         *      In this case we just need to fill %20 in place of blank space
         * 2-   If count of blank space is more than 3
         *      In this case first we need to fill %20. at same time we need 
         *     to shift all the elements to take the position of blank space
         * 3-   If count of blank space is less than 3
         *      In this case we would need to make an extra space to fit MAX
         *      char in bwtween. all the elements has to be pushed towards 
         *      end. as assumption of this API is there would be enough space 
         *      towards end to push the element. if there are not enough 
         *      space, return error .
         */
        if ((str[index] != ' ') && (is_space_flag)) {
            /* CASE 1*/
            if (count == MAX) {
                str [index - count]     = '%';
                str [(index - count) + 1] = '2';
                str [(index -count) + 2] = '0';
                count = 0;
                is_space_flag = FALSE;
            }

            /*  CASE 2 */
            if (count > MAX) {
                str [index - count]     = '%';
                str [(index - count) + 1] = '2';
                str [(index - count) + 2] = '0';
                count -= MAX;
                temp_index_1 = index - count;
                temp_index_2 = index;

                while (str[temp_index_2] != '\0' ) {
                    str[temp_index_1++] = str[temp_index_2++];
                }
                count = 0;
                is_space_flag = FALSE;
                temp_index_1 = 0;
                temp_index_2 = 0;
                last_processed_index = index;
                }

            if (count < MAX) {
                temp_index_1 = len;
                temp_index_2 = len - MAX - count + 1;
                while (temp_index_2 != index) {
                    str [temp_index_1 --] = str [temp_index_2 --];
                }

                str[index - count] = '%';
                str [index - count +1] = '2';
                str [index - count+2] = '0';
                count = 0;
                is_space_flag = FALSE;
                temp_index_1 = 0;
                temp_index_2 = 0;
                last_processed_index = index;

            }
        }
    }
    printf ("\n  END OF %s():", __FUNCTION__);
    return;
}

int main ()
{
    char str1[] = "a   b";

    char *str = NULL;
    clock_t begin = clock();
    str = replace_blanck_space_brute_force_method (str1, strlen(str1));
    clock_t end = clock();
    double time_spent_1 = (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("\n Time spent for API First = %f\n", time_spent_1);
    printf ("\n STRING IS by First API  = %s Len = %lu\n\n", str, strlen (str));

    begin = clock ();
    string_replace_by_api (str1, strlen(str1));
    end = clock ();
    printf ("\n Time spent for API Second  = %f\n", time_spent_1);
    printf ("\n STRING IS By 2nd API  = %s Time spent = %f\n\n", 
            str1, time_spent_1);

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
