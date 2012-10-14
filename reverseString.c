#include <stdio.h>

/*
mayunlong1988@gmail.com
reverse a string of c type
 */

char* reverseString(char* ch){
  char* c = ch;
  int len = 0;
  while(*c++ != '\0'){
    len++;
  }

  int i = 0;
  c = ch;
  for(i = 0; i < len / 2; i++){
    char tempC = *(ch + len - 1 - i);
    *(c + len - 1 - i) = *c;
    *c = tempC;
  }
  return ch;
}

/*
another way to reverse string
 */
void reverse(char* str){
  char* end = str;
  char tmp;
  if(str){
    while(*end){
      ++end;
    }
    --end;
    while(str < end){
      tmp = *str;
      *str++ = *end;
      *end-- = tmp;
    }
  }
}

void main(){
  char ch[] = "hello,world!";
  char* tmp = reverseString(ch);
  // char* ch = "hello,world!";
  // if ch is a pointer, it will be wrong, 'cause pointer cannot be modified
  reverse(ch);
  printf("%s\n", ch);
  printf("%s\n", tmp);
}
