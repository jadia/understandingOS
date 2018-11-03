/*
Que3 (IPC): Write a C/C++ program that creates two processes, a parent and a
child where the child is created via the fork() system call. The parent reads the
content of a file and sends them to child via Interprocess communication (IPC).The
child receives the data send by the parent and write them to another file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define consumerFile "forkandPipe-Consumer"

void main()
{
  int data_processed;
  int file_pipes[2];
  const char some_data[] = "123";
  char buffer[BUFSIZ + 1];
  pid_t fork_result;

  memset(buffer,'\0', sizeof(buffer));

  if(pipe(file_pipes) == 0)
  {
    sprintf(buffer, "%d", file_pipes[0]);
    (void)execl(consumerFile, consumerFile, buffer, (char *)0);
    exit(1);
  }
  else
  {
    data_processed = write(file_pipes[1], some_data, strlen(some_data));
    printf("%d - wrote %d bytes\n", getpid(), data_processed);
  }
  exit(1);
}
