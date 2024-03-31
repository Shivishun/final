#include <stdio.h>

struct Process {
    int pid;        
    int arrival;    
    int burst;      
    int waiting;    
    int turnaround; 
    int completed;  
};

void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;
    int completedProcesses = 0;
    int shortestIndex;

    while (completedProcesses < n) {
        int shortestBurst = -1;

        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrival <= currentTime) {
                if (shortestBurst == -1 || processes[i].burst < shortestBurst) {
                    shortestBurst = processes[i].burst;
                    shortestIndex = i;
                }
            }
        }

        if (shortestBurst == -1) {
            int nextArrival = -1;
            for (int i = 0; i < n; i++) {
                if (!processes[i].completed && (nextArrival == -1 || processes[i].arrival < nextArrival)) {
                    nextArrival = processes[i].arrival;
                }
            }
            currentTime = nextArrival;
        } else {
            processes[shortestIndex].waiting = currentTime - processes[shortestIndex].arrival;
            processes[shortestIndex].turnaround = processes[shortestIndex].waiting + processes[shortestIndex].burst;
            processes[shortestIndex].completed = 1;
            currentTime += processes[shortestIndex].burst;
            completedProcesses++;
        }
    }
}

void printTable(struct Process processes[], int n) {
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival, 
               processes[i].burst, processes[i].waiting, processes[i].turnaround);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival, &processes[i].burst);
        processes[i].pid = i + 1;
        processes[i].completed = 0;
    }

    calculateTimes(processes, n);

    printf("\nGantt Chart for Non-Preemptive Shortest Job First (SJF) Scheduling\n");
    printTable(processes, n);

    return 0;
}
