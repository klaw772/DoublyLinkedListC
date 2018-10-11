//James Blash and Kathleen Law
//CS373 - Operating Systems
//Doubly Linked List Simulator

#include <stdio.h> //including appropriate libraries
#include <stdlib.h>

typedef struct Node { //defining the Node structure and its pointers
  int data;
  struct Node* head;
  struct Node* tail;
  struct Node* next;
  struct Node* previous;
} Node;

Node* head = NULL; //initializing head and tail to be null
Node* tail = NULL;

void makeInitialLinkedList(int data){ //constructs the initial linked list from the array data specified in the main method
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //allocating memory for each new node
  newNode -> data = data; //data of the new node set to the data in the parameter
  if (head==NULL){ //if head is null, setting the pointers of head and tail to the new node
    head = newNode;
    tail = newNode;
    head -> next = NULL;
    head -> previous = NULL;
  }
  else { //if not the first node being added to the list, fixing the tail of the linked list to accommodate for the new node
    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
    tail -> next = NULL;
  }
}


void add(int data){ //adding a new node to the end of the linked list
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //allocating memory
    newNode -> data = data; //setting data of new node
    tail->next = newNode; //fixing tail of linked list
    newNode->previous = tail;
    tail = newNode;
    tail -> next = NULL;
}

void modify(int index, int newData){ //modifying an element in the linked list, providing an index to change and a new value for parameters
  struct Node* current = head; //setting pointer to traverse through linked list
  for(int i = 0; i < index; i++){ //traversing to the desired index
    current = current->next;
  }
  current->data = newData; //data value of the node where the pointer is located is changed to the new data specified in parameter
}

void delete(){ //delete a node from the end of the list
  struct Node* current = tail; //setting pointer to the tail of the linked list
  if(head->next == NULL){ //if there is only one element in the list
    head = NULL;
  }
  else{
    tail->previous->next = NULL; //setting the previous node's next value to null
  }
  tail = tail->previous; //setting tail to the previous node
  free(current); //free the memory of the former tail
}

void printy(){ //print the linked list
  printf("Your current list is: ");
   struct Node* current = head; //setting pointer to traverse through the linked list
   while(current != NULL) { //ensuring that there is still a "next" value to print
      printf("%d ", current->data); //print the data of each node
      current = current->next;
   }
   printf("\n");
}

int main()
{
  char x; //character whose value determines whether the add, modify, or delete method will take place
  int y[5] = {2, 3, 12, 4, 7}; //initial array with values
  for (int i = 0; i < 5; i++){ //iterate through array and set the values of the array into a linked list
    makeInitialLinkedList(y[i]);
  }
  printf("Welcome to the doubly linked list of death!\n"); //lol
  printf("we hate ourselves lol\n"); //tru
  printy(); //print initial linked list
  while (x = getchar() != EOF){ //this is not functional yet but should detect ctrl+d
    printf("Choose an option below by typing the appropriate number, or press Ctrl+D to quit.\n"); //main menu
    printf("1. Add: Add an element to the list\n");
    printf("2. Modify: Modify an existing item\n");
    printf("3. Delete: Delete an item from the list\n");
    scanf(" %c", &x); //scans character
    getchar(); //retrieves character
    if(x == '1'){ //add method
      int data;
      printf("Please enter a number to add to the list:\n");
      scanf(" %d", &data); //scans for a new number to add to the list
      add(data); //performs add
      printy(); //prints list
    }
    else if(x == '2'){ //modify method
      int index;
      printf("Please enter an index to change:\n");
      scanf(" %d", &index); //scans for desired index number of modification
      int data;
      printf("Please enter a new value for that index:\n");
      scanf(" %d", &data); //scans for new value to replace the current value at desired index
      modify(index, data); //performs modify
      printy(); //prints list
    }
    else if(x == '3'){
      delete(); //performs delete method
      printy(); //prints list
    }
  }
  return 0;
}
