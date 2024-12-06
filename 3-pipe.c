#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd[2];
    pipe(fd);
    if(fork() == 0)
    {
        close(fd[0]);
        write(fd[1], "Hello from child", 16);
    }
    else
    {
        close(fd[1]);
        char buffer[16];
        read(fd[0], buffer, 16);
        printf("Parent received: %s\n", buffer);
    }
    return 0;
}