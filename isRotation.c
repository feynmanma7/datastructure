#include <stdio.h> 
#include <string.h>

/*
FLYINGMAN
mayunlong1988 at gmail.com

the best way to solve the problem:
u have a function : isSubstring(s1, s2), to check if s1 is the substring of s2
given two strings: s1, s2. the goal is to check if s1 is the rotation of s2.
ie: "waterbottle" is a rotation of "erbottlewat".
*/

int isRotation(char* s1, char* s2, int len1, int len2){
  if(len1 != len2)
    return 0;
  int i;
  char s2s2[len2+len2];
  strcpy(s2s2, s2);
  strcat(s2s2, s2);

  if(strstr(s2s2, s1) != NULL)
    return 1;
  return 0;
}

void main(){
  char s1[] = "erbottlewat";
  char s2[] = "waterbottle";

  int result =  isRotation(s1, s2, strlen(s1), strlen(s2));
  if(result == 1)
    printf("true\n");
  else
    printf("false\n");
  //  isSubstring(s1, s2, strlen(s1), strlen(s2));
}















