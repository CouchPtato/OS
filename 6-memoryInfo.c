#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Kernel version: \n");
    system("cat /proc/version");

    printf("\nInfo on free and used Memory: \n");
    system("cat /proc/meminfo | awk '/Mem/ {print}'");
    return 0;
}