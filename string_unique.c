/*
 *  ------------------------------------------------------------------
 *  
 * String_unique.c
 * Book: Cracking the coding interview
 * Question: Is Unique: Implement an algorithem to determine if a string has 
 * all unique charters. what if you can not use additional data structure
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
#define MAX_ASCII 128

/*
 * This API checks if all the char in string are unique. it does not use 
 * extra space 
 *
 * Time complexity : O (n^2)
 */
void is_unique (char *str)
{
    if (str == NULL) {
        printf ("\n Not Valid String\n");
        return;
    }
 
    int index = 0;
    int internal_index = 0;
    int length = strlen (str);

    for (index = 0; index < length; index++ ) {
        for (internal_index = index+1; internal_index < length; internal_index++) {
            if (str[index] == str[internal_index]) {
                printf ("\n Not unique string\n");
                return;
                /*
                 * Char might be upper and lower case both. consider case
                 * where we might have same char in both case. we can not 
                 * call it as Unique string
                 */
            } else if (str[index] + ('a' - 'A') == str[internal_index]) {
                printf ("\n Not unique string\n");
                return;
            }
        }
    }
    printf ("\n unique string\n");

}

/*
 * If it is allowed to use extra space, we can have one more API which 
 * would do better job than earlier API. 
 *
 * now we can have hash table containing all ASCI char . and we keep marking 
 * flag if any of the char is used in string. if we hit one more time, we 
 * can return printing it is not unique string other wise it would be 
 */
void is_string_unique (char *str) 
{
    int hash_table [MAX_ASCII] = {0};
    int index = 0, index_arr = 0;
    int length = strlen (str);

    for (index = 0; index < length ; index ++) {
        index_arr = str[index];
        if (index_arr > 'a' && index_arr < 'z') {
            index_arr = index_arr - ('a' - 'A');
        }
        if (hash_table [index_arr]) {
            printf ("\n String %s is not Unique. "
                    "it has %c char duplicate \n",
                    str, str[index]);
                return;
        } else {
            hash_table [index_arr] = 1;
        }
    }
    printf ("\n unique string\n");
}

int main ()
{
    char str[] = "IaiaslkdaklsdalksmdlkasdlkfnalknfklasndklasndadlkasmUnique";
    clock_t begin = clock();
    is_unique (str);
    clock_t end = clock();
    double time_spent_1 = (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("\n Time spent for API is_unique = %f\n", time_spent_1);

    begin = clock ();
    is_string_unique (str);
    end = clock ();
    double time_spent_2 = (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("\n Time spent for API is_string_unique  = %f\n", time_spent_2);
    if (time_spent_1 > time_spent_2) {
        printf (" \n is_unique took more time to execute\n");
    } else {
        printf (" \n is_string_unique took more time to execute\n");
    }

    return 1;
}



#if 0
                                    UNIT TEST
------------------------------------------------------------------------------
MANKAMIS-M-K0FG:feb_2017 mankamis$ ./a.out

 Not unique string

  Time spent for API is_unique = 0.000040

   String IaiaslkdaklsdalksmdlkasdlkfnalknfklasndklasndadlkasmUnique 
   is not Unique. it has i char duplicate

    Time spent for API is_string_unique  = 0.000010

    is_unique took more time to execute
MANKAMIS-M-K0FG:feb_2017 mankamis$

------------------------------------------------------------------------------
#endif 
