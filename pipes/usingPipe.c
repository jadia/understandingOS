#include<stdio.h>
#include<stdlib.h> // exit
#include<string.h> // memset
#include<unistd.h> // pipe, fork, read, write functions

void main()
{
  int data_processed;
  int file_pipes[2]; // creating file descripter for pipe
  const char some_data[] = "123";
  char buffer[BUFSIZ + 1];
  pid_t fork_result; // to save pid

  memset(buffer, '\0', sizeof(buffer));

  if(pipe(file_pipes) == 0)
  {
    fork_result = fork();
    if(fork_result == -1)
    {
      fprintf(stderr, "Fork failure");
      exit(1);
    }
    if(fork_result == 0) // child process will run this
    {
      data_processed = read(file_pipes[0], buffer, BUFSIZ);
      printf("Read %d bytes: %s \n ", data_processed, buffer);
      exit(0);
    }
    else // parent will run this
    {
      data_processed = write(file_pipes[1], some_data, strlen(some_data));
      printf("Wrote %d bytes \n", data_processed);
    }
    exit(0);
  }
}
