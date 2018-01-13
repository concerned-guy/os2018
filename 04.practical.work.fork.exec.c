#include <stdio.h>
#include <unistd.h>

const char *ps[] = { "ps", "-ef", NULL };
const char *fr[] = { "free", "-h", NULL };

int main()
{
    int pid;

    printf("parent");

    if ((pid = fork()) == 0)
        execvp(ps[0], ps);

    if ((pid = fork()) == 0)
        execvp(fr[0], fr);

    return 0;
}
