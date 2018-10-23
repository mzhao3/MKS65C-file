#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//for open
#include <fcntl.h>
//for read
#include <unistd.h>
int main() {
  unsigned int a = open("/test.txt", 0);
  printf ("%d", a);
  // read: returns actual # of bytes read, 0 at end of file
  int  b =read(a, [size of buffer] , 4);
  printf("%d", b);

  return 0;

}
