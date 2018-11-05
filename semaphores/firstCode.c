/*
compile using:
gcc firstCode.c -pthread
*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/types.h>

void main()
{
  /* initialize semaphore */
  sem_t *mutex;

  mutex = sem_open("nitish", O_CREAT, 0777, 0);
  printf("first.\n");
  sem_post(mutex);
}
