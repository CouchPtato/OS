#include <stdio.h>
#include <unistd.h>

int main()
{
    fork();
    printf("This message is from PID: %d\n", getpid());
    return 0;
}