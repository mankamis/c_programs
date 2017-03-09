/*
 *A child plays with a ball on the nth floor of a big building. 
 *The height of this floor is known:
 *
 * (float parameter "h" in meters, h > 0) .
 *
 * He lets out the ball. The ball rebounds for example to two-thirds:
 *
 *(float parameter "bounce", 0 < bounce < 1)
 *
 *of its height.
 *
 * His mother looks out of a window that is 1.5 meters from the ground:
 *
 *(float parameters window < h).
 *
 * How many times will the mother see the ball either falling or bouncing in 
 * front of the window
 *
 * (return a positive integer unless conditions are not 
 * fulfilled in which case return -1) ?
 *
 *Note
 *
 * You will admit that the ball can only be seen if the height of the 
 * rebouncing ball is stricty greater than the window parameter.
 */
#include <stdio.h>
#include <stdlib.h>

int bouncingBall(double h, double bounce, double window) 
{
    double height = h;
    int count = 0;
    if (window < 0)
        return -1;
    while (height > window) {
        if (height > window) {
            count ++;
            printf ("\n Incrementing count down = %d", count);
        }
        height = (height * bounce);

        if (height > window) {
            count ++;
            printf ("\n Incrementing count down = %d", count);
        }
        printf ("\n Height = %f", height);
    }
    printf ("\n Count = %d\n", count);
    if (!count) {
        return -1;
    }
    return count;
}

int main ()
{
    int count = bouncingBall (30, 0.66, 1.5);
    printf ("\n Count final = %d\n", count);
    return 1;
}


