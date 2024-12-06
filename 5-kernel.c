#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Kernel Version: ");
    system("cat /proc/version");
    printf("CPU Type: ");
    system("cat /proc/cpuinfo | grep 'processor\\|model'");
    return 0;
}