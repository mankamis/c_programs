/*
 *Remove all exclamation marks from sentence but ensure a exclamation mark 
 *at the end of string. For a beginner kata, 
 *you can assume that the input data is always a non empty string, 
 *no need to verify it.
 *Examples
 *
 *remove("Hi!") === "Hi!"
 *remove("Hi!!!") === "Hi!"
 *remove("!Hi") === "Hi!"
 *remove("!Hi!") === "Hi!"
 *remove("Hi! Hi!") === "Hi Hi!"
 *remove("Hi") === "Hi!"
 *(For C and clojure please use remove_bang as the function name. 
 *Also, in C it is expected that the pointer 
 *returned by the function was allocated by malloc.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* remove_bang(char* s)
{
    int len = strlen (s);
    char * str = malloc (sizeof (char) * (len+2));   
    memset (str, 0, len+2);
    int i;
    int j = 0;
    for (i = 0; i < len+1; i++) {
        if ((s[i] != '!') && i != (len)) {
            str [j++] = s[i];
        }
        if ((s[i] == '!') && i == (len)) {
            str [j++] = s[i];
        }
        printf ("\nstr[%d] = %c", i, str[i] );
    }

    printf ("\nstring = %s, j = %d", str, j);

        if (str[j-1] != '!') {
            str [j++] = '!'; 
        }
    str[j] = '\0';
    return str;
}
int main ()
{
    char *s = "Hi";
    char *res = remove_bang (s);
    printf ("\n Res = %s", res);
    printf ("\n");
}
