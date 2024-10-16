#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

pthread_t tid[3]; 
int counter; 
pthread_mutex_t lock;

//this function indicates thread synchronization problem, two threads access global variable (counter) at a same time
//for loop allow kernel to do context-switch
void* thread_sync(void* arg) 
{ 
	// pthread_mutex_lock(&lock);

	unsigned long i = 0; 
	counter += 1; //all threads go to this. this is race condition 
	printf("\n Job %d has started\n", counter); 

	for (i = 0; i < (0xFFFFFFFF); i++) //context-switch
		; 
	printf("\n Job %d has finished\n", counter); //this would print the same line for all threads, leading to incorrect output

	// pthread_mutex_unlock(&lock);

	return NULL; 
} 

int main(void) 
{ 
	int i = 0; 
	int ret; 

	int mutex_init = pthread_mutex_init(&lock, NULL); // lock inited
	if(mutex_init != 0) {
		printf("Mutex init has failed!\n");
		return 1;
	}

	while (i < 3) { 
		ret = pthread_create(&(tid[i]), NULL, &thread_sync, NULL); 
		if (ret != 0) 
			perror("Create thread\n");
		i++; 
	} 

	pthread_join(tid[0], NULL); 
	pthread_join(tid[1], NULL); 
	pthread_join(tid[2], NULL);
	pthread_mutex_destroy(&lock);

	return 0; 
} 
