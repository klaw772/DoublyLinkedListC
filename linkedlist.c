#include <stdio.h>
int main()
{
  char x;
  int y[5];

  printf("Welcome to the doubly linked list of death!\n");
  printf("we hate ourselves lol\n");
  printf("Choose an option below by typing the appropriate number.\n");
  printf("1. Add: Add an element to the list\n");
  printf("2. Modify: Modify an existing item\n");
  printf("3. Delete: Delete an item from the list\n");
  scanf("%c", x);


  if(x == '1'){
    add();
  }
  else if(x == '2'){
    modify();
  }
  else if(x == '3'){
    delete();
  }
  else{
    printf("why didn't you pick one of the three omg go back to elementary school");
  }

  return 0;
}
