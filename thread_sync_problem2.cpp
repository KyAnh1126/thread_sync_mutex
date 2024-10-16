#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

int mails = 0;
pthread_mutex_t mutex;

//this function indicate a thread synchronization problem, where two threads access global variable (mails) at a same time
void* play_game(void* test) {
    printf("thread\n");
    for(int i = 0; i < 10000000; ++i) {
        // pthread_mutex_lock(&mutex);
        mails++;
        // pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char* argv[]) {
    pthread_mutex_init(&mutex, NULL);
    pthread_t p1, p2;
    if(pthread_create(&p1, NULL, play_game, NULL) < 0) {
        return 1;
    }
    if(pthread_create(&p2, NULL, play_game, NULL) < 0) {
        return 2;
    }
    if(pthread_join(p1, NULL) < 0) {
        return 3;
    }
    if(pthread_join(p2, NULL) < 0) {
        return 4;
    }
    pthread_mutex_destroy(&mutex);
    printf("mails = %d\n", mails); //mails is incorrect without locking mutex
}