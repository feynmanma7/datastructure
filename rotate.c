#include <stdio.h>
#include <string.h>

void reverse(char*s, int start, int end){
  char* pstart = s + start;
  char* pend = s + end;
  int now = 1;
  int offset = end - start;
  printf("offset = %d\n", offset);
  /* change times: (offset + 1) / 2 */
  while(now <= (offset + 1) / 2){
    printf("%c <--> %c, ", *pstart, *pend);
    char temp = *pstart;
    *pstart = *pend;
    *pend = temp;
    pstart++;
    pend--;
    now++;
  }

  printf("%s\n", s);
}

/* pos : the pos'th position */
void rotate(char* s, int pos, int len){
  reverse(s, 0, pos - 1);
  reverse(s, pos, len - 1);
  reverse(s, 0, len - 1);
}

void main(){
  char s[] = "abcdefgh";
  int pos = 5;
  //reverse(s, 0, 7, strlen(s));
  rotate(s, pos, strlen(s));
  //  printf("%s\n", s);
}
