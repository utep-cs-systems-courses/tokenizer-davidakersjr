#include "stdlib.h"
#include "stdio.h"
#include "tokenizer.h"



int true = 1;

int false = 0;



/* MOVE ALLL OF THIS LOGIC TO tokenizer.c!!!!!!!!!!!!!!!!!!!!!!! */

/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */

int space_char(char c) {
  if (c == ' ' || c == '\t'){
    return true;

  }

  else {

    return false;

  }

}

/* Return true (non-zero) if c is a non-whitespace 

   character (not tab or space).  

   Zero terminators are not printable (therefore false) */

int non_space_char(char c){
  return (!space_char(c));
}

/* Returns a pointer to the first character of the next 

   space-separated token in zero-terminated str.  Return a zero pointer if 

   str does not contain any tokens. */





char *token_start(char *str){
  while (*str != '\0'){
    if (non_space_char(*str)){
      return (str);
    }
    str++;
  }
  return NULL;
}



/* Returns a pointer terminator char following *token*/
char *token_terminator(char *token){
  while (*token != '\0'){
    if (space_char(*token)){
      return (token);
    }
    token++;
  }
  return token;
}



/* Counts the number of tokens in the string argument. */

int count_tokens(char *str){
  int words = 0;
  char* temp = str;

  while (*temp != '\0'){

    temp = token_start(temp);

    if (*temp != '\0'){ words++;}

    temp = token_terminator(temp);

  }

  return words;

}

/* Returns a fresly allocated new zero-terminated string 

   containing <len> chars from <inStr> like end  from start, use maloc to alloate how big word is*/

char *copy_str(char *inStr, short len){
  char *word = malloc((len+1)*(sizeof(char)));
  for (int i = 0; i < len;i++){
    word[i] = inStr[i];
  }

  word[len] = '\0';

  return word;

  //So do i copy the string add a zero at the end and call it a day? is it mem allocation for just one word is it just the whole string what part is the part i actually do idk what

}



/* Returns a freshly allocate*/
char **tokenize(char *str){
  
  int numTokens = count_tokens(str);
  
  char **tokens = malloc((numTokens+1)*(sizeof(char *)));
  
  int tokenIndex = 0;
  int i = 0;
  while(*str!='\0'){
   
    char *startStr = token_start(str);
    
    char *endStr = token_terminator(str);
    while (*endStr != '\0' && space_char(*endStr)) {
      endStr++;
    }
    
    short len = endStr - startStr;
    
    tokens[tokenIndex] = copy_str(startStr, len);
    
    tokenIndex++;
    str = endStr;
    
  }
  tokens[numTokens] = NULL;

  return tokens;

}



/* Prints all tokens. */

void print_tokens(char **tokens){

  int i;

  for(i = 0; tokens[i] != NULL; i++){
    printf("%d: %s\n", i, tokens[i]);

  }

}

/* Frees all tokens and the vector containing themx. using free function with meloc to overwrite the memory */

void free_tokens(char **tokens){

  for (int i= 0; tokens[i] != NULL; i++){
    free(tokens[i]);
  }
  free(tokens);

}

