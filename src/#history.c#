
#include "stdlib.h"
#include "stdio.h"
#include "history.h"
/* Initialize the linked list to keep the history. */

List* init_history(){
   List* list = (List*)malloc(sizeof(List)); 
   list->root = NULL;
   return list;
 
}



/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str){
  Item temp = *list->root;
  int id = 0;
  while(temp.next!=NULL){
    temp.next;
    id++;
  }
  Item *node = (Item*)malloc(sizeof(Item));
  node->id = id;
  node->str = str;
  node->next = NULL;
  temp.next = node;
  *list->root = temp;
}
/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){
  Item temp = *list->root;
  while(temp.id!=id){
    temp.next;
  }
  char *str = temp.str;
  return str;
  
}
/*Print the entire contents of the list. */

void print_history(List *list){
  Item temp = *list->root;
  while (temp.next!=NULL){
    printf(temp.str);
    temp.next;
  }
  printf(temp.str);
}

/*Free the history list and the strings it references. */

void free_history(List *list){
  Item temp = *list->root;
  while(temp.next!=NULL){
    free(temp.str);
    temp.next;
  }
  free(temp.str);
}

