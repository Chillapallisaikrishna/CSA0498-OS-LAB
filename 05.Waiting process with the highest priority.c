#include <stdio.h>

#define MAX_PROCESSES 100

typedef struct Process {
  int id;
  int priority;
  int burst_time;
} Process;

int main() {
  int num_processes, i, j;
  Process processes[MAX_PROCESSES];

  // Take input for the number of processes
  printf("Enter the number of processes: ");
  scanf("%d", &num_processes);

  // Take input for the processes
  for (i = 0; i < num_processes; i++) {
    printf("Enter the details for process %d (priority burst_time): ", i + 1);
    scanf("%d%d", &processes[i].priority, &processes[i].burst_time);
    processes[i].id = i + 1;
  }

  // Sort the processes based on their priority
  for (i = 0; i < num_processes - 1; i++) {
    for (j = 0; j < num_processes - i - 1; j++) {
      if (processes[j].priority < processes[j + 1].priority) {
        Process temp = processes[j];
        processes[j] = processes[j + 1];
        processes[j + 1] = temp;
      }
    }
  }

  // Execute the processes
  printf("\nProcess execution order: \n");
  for (i = 0; i < num_processes; i++) {
    printf("Process %d (priority %d, burst time %d)\n",
           processes[i].id, processes[i].priority, processes[i].burst_time);
  }

  return 0;
}
