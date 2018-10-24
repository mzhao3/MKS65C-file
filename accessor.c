#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//for open
#include <fcntl.h>
//for read
#include <unistd.h>


int main() {

  printf("File test.txt contains the string 'blueberry banana shake'\n");
  // opens file for reading, writing, or both
  int a = open("test.txt", 0);
  printf ("opened file test.txt:  %d\n", a);

  int b = open("test.txt", 0);
  printf ("opened another file test.txt:  %d\n", b);

  int c = close(b);
  printf ("closed file test.txt:  %d\n", c);

  int d = open("hello.txt", 0);
  printf ("opened file hello.txt:  %d\n", d);

  printf("\n");

  /***
  // fd = what table entry is the file in?
  // buf = memory location to read data from
  // cnt = length of buffer
  //
  // size_t read (int fd , void* buf, size_t cnt);
  // reads cnt bytes of input into memory area defined by buf
  // Returns: actual bytes read
  ***/

  printf("a = test.txt...\n");
  printf("Should read 'blueberry banana shake'\n");
  // Need to test: When does it return 0? ( when reaches end of file)
  // How to see what characters are read?
  char * x = malloc(sizeof(char) * 100); //can store 100 characters

  int ab = read(a, x , 22);
  printf("Read(%d, x, 22) reads %d bytes. \n", a, ab);
  //printf("The character(s) read: ");
  printf("x = %s\n", x);

  char * y = malloc(sizeof(char) * 10);

  int ad = read(a, y , 10);
  printf("Read(%d, y, 10) reads %d bytes. \n", a, ad);
  //printf("File is ");
  printf("\n");


  /***
  // fd = what table entry is the file in?
  // buf = memory location to read data from
  // cnt = length of buffer
  //
  // size_t write (int fd , void* buf, size_t cnt);
  // Writes cnt bytes from buf to the file defined by fd
  // Returns: actual bytes read
  ***/

  printf("a = test.txt...\n");
  printf("Writing 'hello world' into test.txt \n");

  const void * buffer = "hello world\n";

  // why does this return -1?
  unsigned int count = 12;
  int val = write(a, buffer, count);
  printf("Returned: %d\n" , val);


  printf("write(%d, 'hello world\\n', 12)\nReturned: %d\n",
  				a,  								val) ;

  int zz = read(a, x , 10);
  printf("Read(%d, x, 10) reads %d bytes. \n", a, zz);
  printf("x = %s\n", x );

  printf("\n");

  close(a);
  printf("closed test.txt\n");
  return 0;

}
