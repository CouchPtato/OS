#include <stdio.h>

void PriorityScheduling(int processes[], int n, int bt[], int priority[]) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    // Sort processes based on priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Calculate waiting time
    wt[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) 
        wt[i] = wt[i - 1] + bt[i - 1];

    // Calculate turnaround time
    for (int i = 0; i < n; i++) 
        tat[i] = wt[i] + bt[i];

    // Display results
    printf("Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], priority[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {10, 1, 2, 1};
    int priority[] = {3, 1, 4, 2};

    PriorityScheduling(processes, n, burst_time, priority);
    return 0;
}
