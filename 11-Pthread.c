#include <stdio.h>
#include <pthread.h>

int sum = 0;
void* add(void* arg) {
    int n = *(int*)arg;
    sum += n;
    pthread_exit(0);
}

int main() {
    pthread_t threads[5];
    int numbers[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) 
        pthread_create(&threads[i], NULL, add, &numbers[i]);
    
    for (int i = 0; i < 5; i++) 
        pthread_join(threads[i], NULL);

    printf("Sum: %d\n", sum);
    return 0;
}
