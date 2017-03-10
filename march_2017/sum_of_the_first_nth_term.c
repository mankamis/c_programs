/*
 *Task:
 *
 *Your task is to write a function which returns the sum of 
 *following series upto nth term(parameter).
 *
 *Series: 1 + 1/4 + 1/7 + 1/10 + 1/13 + 1/16 +...
 *Rules:
 *
 *You need to round the answer upto 2 decimal places and return it as String.
 *If the given value is 0 then it should return 0.00
 *You will only be given Natural Numbers as arguments.
 *Examples:
 *
 *SeriesSum(1) => 1 = "1"
 *SeriesSum(2) => 1 + 1/4 = "1.25"
 *SeriesSum(5) => 1 + 1/4 + 1/7 + 1/10 + 1/13 = "1.57"
 */
#include <stdio.h>
#include <stdlib.h>
#define NUM_DEC 2
char *series_sum(const size_t n) 
{
    if (n == 0) {
        char *result;
        result = malloc (sizeof (char) * (5));
        result [0] = '0';
        result [1] = '.';
        result [2] = '0';
        result [3] = '0';
        result [4] = '\0';
        return result;
    }
    if (n == 1) {
        char *result;
        result = malloc (sizeof (char) * (5));
        result [0] = '1';
        result [1] = '.';
        result [2] = '0';
        result [3] = '0';
        result [4] = '\0';
        return result;
    }
    char *result =  NULL;
    int i = 0;
    float res = 1;
    int int_portion = 0;
    int float_portion = 0;
    int num_of_digit = 0;
    int number = 0;
    int index = 0;
    char c;
    float temp = 0;
    float temp_1 = 1;
    for (i = 1; i < n; i++) {
        temp_1 = (temp_1 + 3.0);
        temp = (1.0 / temp_1);
        res = res + temp; 
        temp = 0;
    }
    int_portion = (int) res;
    temp = res - int_portion;
    temp = temp * 1000;
    index = (int) temp;
    if ( (index  % 10) > 5 ) {
        float_portion = (int) ((res - int_portion) * 100);
        float_portion += 1;
    } else {
        float_portion = (int) ((res - int_portion) * 100);
    }
    number = int_portion;
    while (int_portion) {
        num_of_digit ++;
        int_portion = int_portion / 10;
    }
    result = malloc (sizeof (char) * (num_of_digit + 4));
    index = num_of_digit + 4;
    for (i = index-1; i >=0; i-- ) {
        if (i == index-1) {
            result [i] = '\0';
            continue;
        } 
        if (i >= (index -3)) {
            result [i] = '0' + (float_portion % 10);
            float_portion /= 10;
            continue;
        }
        if (i == (index-4)) {
        result [i] = '.';
        continue;
        }
        result [i] = '0' + (number % 10);
        number = number / 10;
    }
    return result;
}
int main ()
{
    char *res = series_sum (1);
    printf ("\n res = %s\n", res);
    res = series_sum (2);
    printf ("\n res = %s\n", res);
    res = series_sum (3);
    printf ("\n res = %s\n", res);
    res = series_sum (0);
    printf ("\n res = %s\n", res);
    res = series_sum (1);
    printf ("\n res = %s\n", res);
}
