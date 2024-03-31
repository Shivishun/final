#include <stdio.h>
using namespace std;
int main();

struct Process {
    int pid;        
    int arrival;    
    int burst;      
    int completion; 
    int turnaround; 
    int waiting;    
};

void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        
        if (currentTime < processes[i].arrival)
            currentTime = processes[i].arrival;
        processes[i].completion = currentTime + processes[i].burst;

        
        processes[i].turnaround = processes[i].completion - processes[i].arrival;

        processes[i].waiting = processes[i].turnaround - processes[i].burst;

        currentTime = processes[i].completion;
    }
}

void displayResults(struct Process processes[], int n) {
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival, processes[i].burst,
               processes[i].completion, processes[i].turnaround, processes[i].waiting);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter arrival and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        processes[i].pid = i + 1;
        scanf("%d %d", &processes[i].arrival, &processes[i].burst);
    }

    calculateTimes(processes, n);

    displayResults(processes, n);

    return 0;
}
