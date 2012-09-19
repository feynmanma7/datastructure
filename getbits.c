/* getbits */
#include <stdio.h>
/* Get bits from x, start from s, and 
   the length is len. The right end bit is 0.
*/
unsigned getbits(unsigned x, int s, int len){
  return (x >> (s + 1 - len) & ~( ~0 << len));
}

void main(){
  unsigned x = 0xffffffff;
  int s = 10, len = 3;
  unsigned result = getbits(x, s, len);
  printf("%u\n", result);
}
