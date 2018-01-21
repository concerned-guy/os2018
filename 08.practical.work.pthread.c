#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 10

typedef struct {
    char type;
    int amount;
    char unit;
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void *produce(void *arg) {
    item **items = arg;
    while (*items) {
        while ((first + 1) % BUFFER_SIZE == last)
            ;
        printf("produce: first = %d, last = %d\n", (first + 1) % BUFFER_SIZE, last);
        memcpy(&buffer[first], *items, sizeof(item));
        first = (first + 1) % BUFFER_SIZE;
        items++;
    }
}

void *consume(void *arg) {
    int nitems = *((int*) arg);
    while (nitems > 0) {
        item i;
        while (first == last)
            ;
        printf("consume: first = %d, last = %d\n", first, (last + 1) % BUFFER_SIZE);
        memcpy(&i, &buffer[last], sizeof(item));
        last = (last + 1) % BUFFER_SIZE;
        nitems--;
    }
}

int main()
{
    pthread_t tidp;
    pthread_t tidc;
    item item1 = { 0, 7, 0 };
    item item2 = { 1, 99, 1 };
    item item3 = { 0, 3, 0 };
    item *items[] = { &item1, &item2, &item3, NULL };
    int nitems = 2;
    pthread_create(&tidp, NULL, &produce, items);
    pthread_create(&tidc, NULL, &consume, &nitems);
    pthread_join(tidc, NULL);
    return 0;
}
