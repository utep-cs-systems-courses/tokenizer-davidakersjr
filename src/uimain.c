#include <stdio.h>
#include "tokenizer.h"
#include "history.h"


char main (){
  //add something here as a basic ui function with
  List *list = init_history();
  while (1){
    printf("0 - Exit, 1 - Tokenize, 2 - History, 3 - Find history of item at ID \n");
    printf(">");
    char input[25];
    fgets(input, 25, stdin);

    switch(input[0]){

    case'1':
      printf("Enter string to tokenize \n");
      printf(">");
      char str [25];
      char *c = fgets(str, 25, stdin);
      puts(c);
    
      char **tokens = tokenize(c);
      
      print_tokens(tokens);
      
      add_history(list,c);
      
      break;
    case'2':
        
      print_history(list);
      break;
  
    case'3':
      printf("Enter ID");
      
      int numID;
      scanf("%10d",numID);
      get_history(list,numID);
      break;
      
    case'0':
      free_history(list);
      break;

    default:
      printf("INVALID \n");
      break;
    /* puts(c); */
    }
  }
}
