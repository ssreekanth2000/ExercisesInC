/*
Code which modifies count of the remianing deck on the basis of the uses input

It checks if the input is one of the face cards and if not checks if its a
valid number and makes appropriate changes to the count value.

card_name:- Input by the user
count:- The value of the deck.

*/
#include <stdio.h>
#include <stdlib.h>
int count=0;

/* Changes the count value accoridng to the input


   val: The value of the card input by the user

*/
int card_valid(int val){
  if ((val>2)&&(val<7)){
    count++;

  } else if(val==10){
   count--;
  }
  printf("Current count: %i\n",count );
    return 0;
  }
/*
Checks if first char of card_name is X**

card_name:- Input by the user
** I know this is a very redundant function but I am implementing it anyway to
undertstand return better
*/
int is_X(char* card_name){
  if(card_name[0]!='X'){
    return 1;

  }else{
    return 0;
  }
}
/*
Scans for input and assigns first 2 characters to card_name.

I wrote this to understand how passing values in fucntions will work.
*/
int scan_input(char* card_name){
  scanf("%2s",card_name);

}



int main()
{
  char card_name[3];

  do {
    puts("Enter the card_name: ");
    scan_input(card_name);
    int val =0;
    switch(card_name[0]) {
      case 'K':
      case 'Q':
      case 'J':
          val=10;
          break;
      case 'A':
          val=11;
          break;// We would be done with switch
      case 'X':
          continue;
      default:

          val = atoi(card_name);
          if ((val < 1) || (val > 10)){
            puts("I don't understand that value!");
            continue;// To make sure it stays in the loop.
          }
        }
        card_valid(val);{};


    }
    while(is_X(card_name));
    return 0;

    }
