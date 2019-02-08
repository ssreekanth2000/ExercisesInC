/*
Code which modifies count of the remianing deck on the basis of the uses input

It checks if the input is one of the face cards and if not checks if its a
valid number and makes appropriate changes to the count value.

card_name:- Input by the user
count:- The value of the deck.

*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int i=0;
int exitn =1;
int x;
int array[10];
char input_1[2];
int length;
int sum;
int scanf_flag;
/*
Checks if the input is a 2 digit number and adds it to the sum if it is.

   val: The value of the integer input by the user
  length: The length of the input

*/
int is_long(int length,int val){
  if (length>2){
    printf("too  long\n" );

  }
  else{
    sum=sum+val;
  }

}
/*
Checks if the first char of the input is X and quits if it is.

   input_1: The input by the user

*/

int is_X(char* input_1){
  if(input_1[0]!='X'){
    return 1;

  }else{
    return 0;
  }
}
/*
Checks if the input is EOF and exits if it is.

   input_1: The input by the user

*/

int is_EOF(int scanf_flag){
  if(scanf_flag==EOF){
    return 0;

  }else{
    return 1;
  }
}

int main()

{
  while (i<10 && is_EOF(scanf_flag)) {
    printf("Please input a two digit number \n");


    scanf_flag=scanf("%3s", input_1);

    int val= atoi(input_1);
    array[i]=val;
    if (array[i]==0) {
      printf("Your input is not an integer\n" );
      array[i]=0;

    }

    length = strlen(input_1);


    is_long(length,val);

    i=i+1;

    printf("%i\n",sum );



  }
  if (i==10) {
    printf("Out of space\n");
    /* code */
  }
  printf("%i\n",sum);
  //printf("%i\n",array );




  }
