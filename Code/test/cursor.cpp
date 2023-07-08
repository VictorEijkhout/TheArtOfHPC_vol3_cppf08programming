#include <stdio.h>

int main() {
  printf("a\n");
  printf( "%c[0;0H",(char)27);
  printf("b\n");
  return 0;
}
