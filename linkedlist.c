#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int data;
  struct Node* head;
  struct Node* tail;
  struct Node* next;
  struct Node* previous;
} Node;

Node* head = NULL;
Node* tail = NULL;

void makeInitialLinkedList(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode -> data = data;
  if (head==NULL){
    head = newNode;
    tail = newNode;
    head -> next = NULL;
    head -> previous = NULL;
  }
  else {
    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
    tail -> next = NULL;
  }
}


void add(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
    tail -> next = NULL;
}

void modify(int index, int newData){
  struct Node* current = head;
  for(int i = 0; i < index; i++){
    current = current->next;
  }
  current->data = newData;
}

void delete(){
  struct Node* current = tail;
  if(head->next == NULL){
    head = NULL;
  }
  else{
    tail->previous->next = NULL;
  }
  tail = tail->previous;
  free(current);
}

void printy(){
  printf("Your current list is: ");
  //start from the beginning
   struct Node* current = head;
   //move to the end of the list
   while(current != NULL) {
      printf("%d ", current->data);
      current = current->next;
   }
   printf("\n");
}

int main()
{
  char x;
  int y[5] = {2, 3, 12, 4, 7};
  for (int i = 0; i < 5; i++){
    makeInitialLinkedList(y[i]);
  }
  printf("Welcome to the doubly linked list of death!\n");
  printf("we hate ourselves lol\n");
  printy();
  while (x = getchar() != EOF){
    printf("Choose an option below by typing the appropriate number, or press Ctrl+D to quit.\n");
    printf("1. Add: Add an element to the list\n");
    printf("2. Modify: Modify an existing item\n");
    printf("3. Delete: Delete an item from the list\n");
    scanf(" %c", &x);
    getchar();
    if(x == '1'){
      int data;
      printf("Please enter a number to add to the list:\n");
      scanf(" %d", &data);
      add(data);
      printy();
    }
    else if(x == '2'){
      int index;
      printf("Please enter an index to change:\n");
      scanf(" %d", &index);
      int data;
      printf("Please enter a new value for that index:\n");
      scanf(" %d", &data);
      modify(index, data);
      printy();
    }
    else if(x == '3'){
      delete();
      printy();
    }
  }
  return 0;
}
