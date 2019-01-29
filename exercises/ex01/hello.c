#include <stdio.h>
int x=5;//Added X. This lead to some specific lines in the .s file generated
int a = 3;//Adding these adds a lot of lines to hello.c
int b = 4;

int main() {
    int c = a+b;
    printf("c is %d\n",c );

    if (c%2 == 0) {
          printf("c is even\n");
      } else {
          printf("c is odd\n");
      }
    printf("%i!\n",x);//Printing the value of X
    return 0;// When I am running the -02 flag, i see a lot of comments
    //generated in the command line but no difference in the output. Maybe i am
    //using the -02 option wrong?
}
