#include <stdio.h>
#include <stdlib.h>

int power_of (int num, int base)
{
    int i = 0;
    int result = 1;
    for (i = 0; i<num; i++) {
        result = result * base;
    }
    printf ("\n num = %d, base = %d res = %d\n", num, base, result);
    return result;
}
int digPow(int n, int p) {
    int num = n;
    int count = 0;
    int index = 0;
    int digit = 0;
    int temp_num = n;
    while (num != 0) {
        count ++;
        num = num / 10;
    }
    num = 0;
    count = count + p;
    printf (" \n Count = %d\n", count);
    while (n) {
        digit = n % 10;
        n = n / 10;
        printf (" \n Digit  = %d\n", digit);
        count --;
        num = num + power_of ((count ) , digit);
    }
    n = temp_num;

    if ((num % n) == 0) {
        return (num / n);
    }
    return -1;
}

int main ()
{
    int res = digPow (89, 1);
    printf ("\n res = %d\n", res);
}
