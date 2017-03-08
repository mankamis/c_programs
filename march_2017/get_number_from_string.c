/*Write a function which removes from string all non-digit 
 * characters and parse the remaining to number. E.g: "hell5o wor6ld" -> 56
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int power_of (int num, int base)
{
    int i = 0;
    int result = 1;
    for (i = 0; i<num; i++) {
        result = result * base;
    }
    printf ("\n num = %d, base = %d, result = %d\n", num, base, result);
    return result;
}
int get_number_from_string(const char *src) {
    int number = 0;
    int len = strlen (src);
    int num_of_digit = 0;
    int i = 0;

    for (i = (len - 1); i >= 0; i--) {
        if (src[i] >= '0' && src[i] <= '9') {
            
            number = number + ((src[i] - '0' ) * power_of (num_of_digit, 10)); 
            num_of_digit++;
            printf ("\n num = %d, num_of_digit = %d, src[%d] = %d\n", 
                    number, num_of_digit, i, src[i]);
        }
    }
    return number;
}
int main ()
{
    char *str = "hell5o wor6ld";
    int num = 0;
    num = get_number_from_string (str);
    printf ("\n Num = %d\n ", num);
}
