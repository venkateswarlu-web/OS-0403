#include <stdio.h>
int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], waiting_time[n], turnaround_time[n];
    int total_wt = 0, total_tat = 0;

    // Input burst times
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // FCFS Scheduling
    waiting_time[0] = 0; // First process has 0 waiting time

    // Calculate waiting time for each process
    for (i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
    }

    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    // Calculate total waiting time and total turnaround time
    for (i = 0; i < n; i++) {
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    // Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);

    // Gantt Chart
    printf("\nGantt Chart:\n|");
    for (i = 0; i < n; i++) {
        printf(" P%d |", i + 1);
    }

    printf("\n0");
    for (i = 0; i < n; i++) {
        printf("\t%d", turnaround_time[i]);
    }

    printf("\n");

    return 0;
}
