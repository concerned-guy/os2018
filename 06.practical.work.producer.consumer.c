#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

typedef struct {
    char type;  // 0=fried chicken, 1=french friez
    int amount; // pieces or weight
    char unit;  // 0=pieces, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
    while ((first + 1) % BUFFER_SIZE == last) {

    }
    memcpy(&buffer[first], i, sizeof(item));
    first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
    item *i = malloc(sizeof(item));
    while (first == last) {

    }
    memcpy(i, &buffer[last], sizeof(item));
    last = (last + 1) % BUFFER_SIZE;
    return i;
}

int main()
{
    item item1 = {0, 10, 0};
    item item2 = {1, 100, 1};

    printf("1st produce(): ");
    produce(&item1);
    printf("first = %d, last = %d\n", first, last);
    printf("2nd produce(): ");
    produce(&item2);
    printf("first = %d, last = %d\n", first, last);
    printf("1st consume(): ");
    consume();
    printf("first = %d, last = %d\n", first, last);
    return 0;
}
