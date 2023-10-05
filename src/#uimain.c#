#include <stdio.h>
#include "tokenizer.h"
#include "history.h"


char main (){
  //add something here as a basic ui function with a
  while (1){
    printf(">");
    char str[25];
    char *c = fgets(str, 25, stdin);
    puts(c);

    puts("0");
    char **tokens = tokenize(c);
    
    puts("1");
    print_tokens(tokens);
    
    List *list;
    puts("2");
    add_history(list, c);
    puts("3");
    print_history(list);
    puts("4");
    free_tokens(tokens);
    
    
    if (c[0] == '0'){
      free_history(list);
      break;
    }
    /* puts(c); */
  }
}
