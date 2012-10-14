#include <stdio.h>

/*
FLYINGMAN
mayunlong1988 at gmail.com
remove the duplicate characters in a string without using any additional buffer. one or two additional variables are fine.

maybe the best way is to use a 256 array to store the visited flags

a pointer cannot be modified! so we use an array to store the result
*/
char* removeDupChars(char result[], char* ch){
  int checker = 0;
  int flag[256];
  int i;

  for(i = 0; i < 256; i++){
    flag[i] = 0;
    result[i] = '\0';
  }  

  int now = 0;
  while(*ch != '\0'){
    int val = *ch - '\0';
    if(flag[val] == 0){
      result[now++] = *ch;
      flag[val] = 1;
    }
    ch++;
  }

  return result;
}


void main(){
  char ch[] = "hello,world!hello,flyingman!";
  char result[256];
  char *c  = removeDupChars(result, ch);
  printf("%s\n", c);
}
