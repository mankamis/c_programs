/*
 *  ------------------------------------------------------------------
 *  
 * permutation.c
 * Book: Cracking the coding interview
 * Question:  Given two string, write a method to decide if one is a 
 * permutation of the other
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

void string_permutation_check (char * str1, char *str2)
{
    if ((str1 == NULL) || (str2 == NULL)) {
        printf ("\n There is nothing to check . One of String is NULL\n");
        return;
    }

    int len_str1 = strlen (str1);
    int len_str2 = strlen (str2);
    if (len_str1 != len_str2) {
        printf ("\n %s is not permutation of %s\n", str2, str1);
        return;
    }

    int index_arr = 0;
    int index = 0;
    signed int arr [MAX_ASCII] = {0};

    for (index = 0; index < len_str1; index ++) {
        index_arr = str1[index];
        arr [index_arr] = arr[index_arr] + 1;
        index_arr = str2[index];
        arr [index_arr] = arr[index_arr] - 1;

    }
    for (index = 0 ; index < MAX_ASCII; index++) {
        if (arr[index] ) {
            printf ("\n %s is not  permutation of %s\n", str2, str1);
            return;
        }
    }
    printf ("\n %s is permutation of %s\n", str2, str1);
    return ;
}

int main ()
{
    char str1[] = "abcd";
    char str2[] = "bcda";
    clock_t begin = clock();
    string_permutation_check (str1, str2);
    clock_t end = clock();
    double time_spent_1 = (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("\n Time spent for API is_unique = %f\n", time_spent_1);

    char str3[] = "ABCD";
    char str4[] = "XVDR";
    begin = clock ();
    string_permutation_check (str3, str4);
    end = clock ();
    time_spent_1 = (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("\n Time spent for API is_unique = %f\n", time_spent_1);

    return 1;
}



#if 0
                                    UNIT TEST
------------------------------------------------------------------------------
MANKAMIS-M-K0FG:feb_2017 mankamis$ ./a.out

 bcda is permutation of abcd

  Time spent for API is_unique = 0.000044

  XVDR is not  permutation of ABCD

  Time spent for API is_unique = 0.000004
 MANKAMIS-M-K0FG:feb_2017 mankamis$

------------------------------------------------------------------------------
#endif 
