/*compile using -pthread
gcc secondFile.c -pthread*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h> // sem_open
#include <fcntl.h> // O_CREAT
#include <sys/types.h> // sem_t

int main()
{
  /* initialize semaphore */
  sem_t *mutex;

  mutex = sem_open("nitish", 0);
  // printf("%u\n", sem_open("/nitish", O_CREAT, 0777, 0));
  sem_wait(mutex);
  printf("second.\n");
  return 0;
}
