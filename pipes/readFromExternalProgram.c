/*
Read output of external program using pipes
*/

#include<stdio.h>
#include<stdlib.h> // exit
#include<string.h> // memset

void main()
{
  FILE *read_fp;
  char *buffer = calloc(BUFSIZ+1, sizeof(char));
  //char buffer[BUFSIZ + 1];
  int chars_read;
  //memset(buffer, '\0', sizeof(buffer));
  read_fp = popen("uname -a", "r");

  if(read_fp != NULL)
  {
    // read from read_fp and store in buffer
    /*
    The  function  fread() reads nmemb items of data, each size bytes long,
    from the stream pointed to by stream,  storing  them  at  the  location
    given by ptr.
    */
    chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
    if(chars_read > 0)
    printf("Output was:= \n %s \n", buffer);

    pclose(read_fp);
    exit(EXIT_SUCCESS);
  }
  exit(EXIT_FAILURE);
}
