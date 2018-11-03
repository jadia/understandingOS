#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void main(int argc, char *argv[])
{
  int data_processed;
  char buffer[BUFSIZ + 1];
  int file_descriptor;

  memset(buffer, '\0', sizeof(buffer));
  sscanf(argv[1], "%d", &file_descriptor);
  data_processed = read(file_descriptor, buffer, BUFSIZ);

  printf("%d - reada %d byte: %s \n", getpid(), data_processed, buffer);
  exit(0);
}
