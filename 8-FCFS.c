#include <stdio.h>

void FCFS(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    float total_wt = 0, total_tat = 0;
    wt[0] = 0;

    for (int i = 1; i < n; i++) 
        wt[i] = wt[i - 1] + bt[i - 1];
    
    for (int i = 0; i < n; i++)
    { 
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) 
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
        
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = 3;
    int burst_time[] = {10, 5, 8};
    FCFS(processes, n, burst_time);
    return 0;
}
