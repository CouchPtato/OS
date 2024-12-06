#include <stdio.h>

#define MAX 100

// Function to display memory allocation status
void displayAllocation(int allocation[], int n) {
    printf("\nBlock Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        } else {
            printf("Process %d -> Not Allocated\n", i + 1);
        }
    }
}

// First-Fit allocation
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++) { // For each process
        for (int j = 0; j < m; j++) { // Find the first suitable block
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    displayAllocation(allocation, n);
}

// Best-Fit allocation
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++) { // For each process
        int bestIndex = -1;
        for (int j = 0; j < m; j++) { // Find the smallest suitable block
            if (blockSize[j] >= processSize[i]) {
                if (bestIndex == -1 || blockSize[j] < blockSize[bestIndex]) {
                    bestIndex = j;
                }
            }
        }
        if (bestIndex != -1) {
            allocation[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
        }
    }
    displayAllocation(allocation, n);
}

// Worst-Fit allocation
void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++) { // For each process
        int worstIndex = -1;
        for (int j = 0; j < m; j++) { // Find the largest suitable block
            if (blockSize[j] >= processSize[i]) {
                if (worstIndex == -1 || blockSize[j] > blockSize[worstIndex]) {
                    worstIndex = j;
                }
            }
        }
        if (worstIndex != -1) {
            allocation[i] = worstIndex;
            blockSize[worstIndex] -= processSize[i];
        }
    }
    displayAllocation(allocation, n);
}

int main() {
    int blockSize[MAX], processSize[MAX];
    int originalBlockSize[MAX];
    int m, n;

    printf("Enter the number of blocks: ");
    scanf("%d", &m);
    printf("Enter the sizes of the blocks:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
        originalBlockSize[i] = blockSize[i]; // Save original block sizes
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    printf("\n--- First-Fit Allocation ---\n");
    firstFit(blockSize, m, processSize, n);

    // Reset block sizes for next allocation
    for (int i = 0; i < m; i++) {
        blockSize[i] = originalBlockSize[i];
    }

    printf("\n--- Best-Fit Allocation ---\n");
    bestFit(blockSize, m, processSize, n);

    // Reset block sizes for next allocation
    for (int i = 0; i < m; i++) {
        blockSize[i] = originalBlockSize[i];
    }

    printf("\n--- Worst-Fit Allocation ---\n");
    worstFit(blockSize, m, processSize, n);

    return 0;
}
