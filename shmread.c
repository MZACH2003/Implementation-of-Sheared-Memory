#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
void main(){
	int i;
	void *shared_memory;
	char buff[100];
	int shmid;
	key_t key=ftok("shmfile",65);
	shmid=shmget(key,1024,0666|IPC_CREAT);
	printf("Key of shared m/m is :%d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("Data read from shared m/m is :%s",(char *)shared_memory);
}

