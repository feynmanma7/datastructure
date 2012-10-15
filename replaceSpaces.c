#include <stdio.h>
#include <string.h>
#include <memory.h>

/*
FLYINGMAN
mayunlong1988 at gmail.com
the best way to solve the problem:
replace all spaces in a string with '%20'.
*/

void replaceSpaces(char rc[], char ch[], int len){
  int i;
  int now = 0;
  for(i = 0; i < len; i++){
    if(ch[i] != ' '){
      rc[now++] = ch[i];
    } else{
      rc[now++] = '%';
      rc[now++] = '2';
      rc[now++] = '0';
    }
  }
  rc[now] = '\0';
}

int main(){
  char ch[] = " hello world  this is mayunlong";
  int len = strlen(ch);
  char rc[len*3];
  memset(rc, 0, sizeof(rc));
  replaceSpaces(rc, ch, len);

  printf("%s\n len = %d\n", rc, len);
  return 0;
}
