/*
 *  ------------------------------------------------------------------
 *  
 * heap_b_tree.c
 * Heap implementation
 * Question:  Implement Heap short  
 *
 *  MAy 2017, Mankamana Mishra
 * 
 * Copyright (c) 2017 by Mankamana Mishra.
 * All rights reserved.
 *------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/*
 * Global Veriable
 */
int heap_size = 0;


/* max_heapify
 *
 * In order to maintain the max-heap property this API is called. 
 *
 * Return : Void
 *
 * Argument: int *a 
 * IN      : An arry a
 *
 * Argument: int index
 * IN      : index in array to check max heap property
 *
 */
void 
max_heapify (int *a, int index) 
{
    printf ("\n %s():%d called with %p & %d", __FUNCTION__, __LINE__, a, index);
    if (a == NULL) {
        assert (0);
    }

    if (index >= heap_size) {
        printf ("\n Invalid Index\n");
        return;
    }

    int left = 0, right = 0, largest = 0, temp = 0;

    left = 2*index; /* Left child is at 2*i position of parent*/ 
    right = left+1; /* Right child is at 2*i + 1 position of parent*/

    /* Check if index is at right place. it means we need to check if index
     * position content maintains max heap property*/
    if ((left <= heap_size) && (a[left] > a[index])) {
        largest = left;
    } else {
        largest = index;
    }

    if ((right <= heap_size) && a[right] > a[largest]) {
        largest = right;
    }

    printf ("\n Largest = a[%d] : largest %d\n", a[largest], largest);
    temp = a[index];
    a[index] = a[largest];
    a[largest] = temp;
    max_heapify (a, largest);
}

int main ()
{
    int a[] = {0, 16,4,10,14,7,9,3,2,8,1};
    int i;
    heap_size = sizeof (a) / sizeof (int);
    printf ("\n Size of Heap = %d", heap_size);
    max_heapify (a, 2);
    for (i = 0; i < heap_size; i++) {
        printf ("\t %d", a[i]);
    }
    printf ("\n");
}
