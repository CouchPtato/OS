#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("Child process is executing\n");
    }
    else
    {
        wait(NULL);
        printf("Parent process is executing\n");
    }
    return 0;
}