#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> //for open
#include <unistd.h> //for read


int main() {
  printf("\n========================================================\n");

  printf("File test.txt contains the string 'blueberry banana shake'\n");
  // opens file for reading, writing, or both
  int a = open("test.txt", 2);
  printf ("opened file test.txt:  %d\n", a);

  int b = open("test.txt", 0);
  printf ("opened another file test.txt:  %d\n", b);

  int c = close(b);
  printf ("closed file test.txt:  %d\n", c);

  int d = open("hello.txt", 0);
  printf ("created file hello.txt:  %d\n", d);

  /***
  // fd = what table entry is the file in?
  // buf = memory location to read data from
  // cnt = length of buffer
  //
  // size_t read (int fd , void* buf, size_t cnt);
  // reads cnt bytes of input into memory area defined by buf
  // Returns: actual bytes read
  ***/

  printf("\nFile is a = test.txt...\n");
  printf("Reading 'blueberry banana shake'\n");

  char x;

  int ab = read(a, &x , 4);
  printf("Read(%d, &x, 4) reads %d bytes. \n", a, ab);
  //printf("The character(s) read: ");
  //printf("x = %c\n", x );


  char y;
  //int ac = read(c, &y , 35);
  //printf("Read(%d, &y, 35) reads %d bytes. \n", c, ac);
  //printf("The character(s) read: ");
  //printf("y = %c\n", y );

  int ad = read(a, &y , 10);
  printf("read(%d, &y, 10) reads %d bytes. \n\n", a, ad);

  /***
  // fd = what table entry is the file in?
  // buf = memory location to read data from
  // cnt = length of buffer
  //
  // size_t write (int fd , void* buf, size_t cnt);
  // Writes cnt bytes from buf to the file defined by fd
  // Returns: actual bytes read
  ***/

  printf("File is a = test.txt...\n");
  printf("Writing 'hello world' into test.txt \n");

  int xx = write(a, "hello world\n", 0);
  //printf("%d\n" , strlen("hello world\n"));
  printf("write(%d, 'hello world\\n', %d). Returned %d.\n", a, strlen("hello world\n"), xx) ;

  int zz = read(a, &x , 10);
  printf("Read(%d, &x, 10) reads %d bytes. \n", a, zz);
  printf("Read entire file. \n");
  printf("x = %c\n", x );


  close(a);
  printf("closed test.txt");
  printf("\n========================================================\n");

  return 0;

}
