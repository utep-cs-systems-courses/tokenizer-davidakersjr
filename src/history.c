
#include "stdlib.h"
#include "stdio.h"
#include "history.h"
/* Initialize the linked list to keep the history. */

List* init_history(){
  List* list = malloc(sizeof(List)); 
  list->root = malloc(sizeof(Item));
  list->root = NULL;
  return list;
 
}



/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str){
  
  Item *temp = list->root;
  
  int id = 0;
  
  char *copyStr = str;
  
  if (list->root ==NULL){
    list->root = malloc(sizeof(Item));
    
   
    list->root -> id = 0;
    
    list->root -> str = copyStr;
    
    list->root -> next = NULL;
    
  }
  else {
    
    while(temp->next!=NULL){
      temp = temp->next;
      id++;
      
    }
    
    temp->next = malloc(sizeof(Item));
    temp->next->id = id;
    temp->next->str = copyStr;
    temp->next->next = NULL;
   
  }
}
/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){
  Item *temp = list->root;
  while(temp->id!=id){
    temp = temp->next;
  }
  char *str = temp->str;
  return str;
  
}
/*Print the entire contents of the list. */

void print_history(List *list){
  Item *temp = list->root;
  while (temp!=NULL){
    printf("%d: %s\n",temp->id, temp->str);
    temp = temp->next;
  }
 
}

/*Free the history list and the strings it references. */

void free_history(List *list){
  Item *temp = list->root;
  while(temp->next!=NULL){
    free(temp->str);
    temp = temp->next;
  }
  free(temp->str);
}

