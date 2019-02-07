/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;
// int check_heap(int var2){
//   int address_1=&var2;
//
//
// }

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *p1 = malloc(128);
    void *p2 = malloc(16);
    void *p3 = malloc(16);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("p1 points to %p\n", p1);
    printf ("p2 points to %p\n", p2);
    printf ("p3 points to %p\n", p3);
    printf ("s points to %p\n", s);

    return 0;
}
//output
// p2 points to 0x1304130
// p3 points to 0x1304150
//The difference is 32 when calculated which makes sense as 16_16 is 32.
