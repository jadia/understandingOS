#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>

#define MAX_BUFFER 1024
#define OUTPUTFILE "outputfile.txt"
#define INPUTFILE "producerInput.txt"

void main()
{

	key_t key = ftok(INPUTFILE, 420);

	int shmid = shmget(key,	MAX_BUFFER, 0666|IPC_CREAT);

	char *str = (char *) shmat(shmid, NULL, 0);

	printf("Data read from the memory: ");

	int i=0;
/*
	while(str[i])
	{
		printf("%c ", str[i]);
		i++;
	}
*/
	FILE *fp;
	if((fp = fopen(OUTPUTFILE,"w")) == NULL)
	{
		perror("Input file: ");
		exit(1);
	}

//	i = 0;
	while(str[i])
	{
		fprintf(fp,"%c ",str[i]);
		i++;
	}

}
