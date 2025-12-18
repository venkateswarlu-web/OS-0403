#include <stdio.h>

struct Process {
    int pid;        // Process ID
    int bt;         // Burst time
    int rt;         // Remaining time
    int wt;         // Waiting time
    int tat;        // Turnaround time
};

int main() {
    int n, tq; // number of processes and time quantum
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time of Process %d: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].wt = 0;
        p[i].tat = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int t = 0; // Current time
    int done;

    // Round Robin Scheduling
    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (p[i].rt > 0) {
                done = 0; // Still processes left

                if (p[i].rt > tq) {
                    t += tq;
                    p[i].rt -= tq;
                } else {
                    t += p[i].rt;
                    p[i].wt = t - p[i].bt;
                    p[i].rt = 0;
                }
            }
        }
    } while (!done);

    // Calculate turnaround time
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].bt + p[i].wt;
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    // Display results
    printf("\nRound Robin Scheduling (Time Quantum = %d):\n", tq);
    printf("PID\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
