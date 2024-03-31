#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define MAX_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t mutex, empty, full;

void *producer(void *arg) {
    int produced_item = 0;
    while (produced_item < MAX_ITEMS) {
        sem_wait(&empty);
        sem_wait(&mutex);

        printf("Producer produced item %d\n", produced_item);
        buffer[in] = produced_item;
        in = (in + 1) % BUFFER_SIZE;
        produced_item++;

        sem_post(&mutex);
        sem_post(&full);

        usleep(100000); 
    }
    return NULL;
}

void *consumer(void *arg) {
    int consumed_item = 0;
    while (consumed_item < MAX_ITEMS) {
        sem_wait(&full);
        sem_wait(&mutex);

        int item = buffer[out];
        printf("Consumer consumed item %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        consumed_item++;

        sem_post(&mutex);
        sem_post(&empty);

        usleep(200000); 
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
