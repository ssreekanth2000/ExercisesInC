/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;//When I compile this code, it warns me saying that the function foo
    //retruns the address of a local variable
    int array[SIZE];

    //printf("%p\n", array); When I comment the print, it removes that error
    // but gives me an error for the return array about returning address of
    //local variable.

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}
//I get a segementation fault when i try to run it.
void bar() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
