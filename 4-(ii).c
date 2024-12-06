#include <stdio.h>
#include <unistd.h>

int main()
{
    if (fork() == 0)
    {
        printf("Child process is executing (PID: %d)\n", getpid());
    }
    else
    {
        printf("Parent process is executing (PID: %d)\n", getpid());
    }
    return 0;
}