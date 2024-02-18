#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int task_id;
    int start_time;
    int finish_time;
} Task;

typedef struct {
    int machine_id;
    int task_id;
    int start_time;
    int finish_time;
} MachineTask;

int main() {
    int num_tasks, num_machines;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    Task tasks[num_tasks];
    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task ID, start time, and finish time for task %d: ", i+1);
        scanf("%d %d %d", &tasks[i].task_id, &tasks[i].start_time, &tasks[i].finish_time);
    }

    printf("Enter the number of machines: ");
    scanf("%d", &num_machines);

    MachineTask machines[num_machines][num_tasks];
    int machine_indices[num_machines];
    for (int i = 0; i < num_machines; i++) {
        machine_indices[i] = 0;
    }

    // Assign tasks to machines based on their finish times
    for (int i = 0; i < num_tasks; i++) {
        int min_finish_time = machines[0][0].finish_time;
        int min_index = 0;

        // Find machine with earliest finish time
        for (int j = 0; j < num_machines; j++) {
            if (machines[j][machine_indices[j]].finish_time < min_finish_time) {
                min_finish_time = machines[j][machine_indices[j]].finish_time;
                min_index = j;
            }
        }

        // Assign task to the machine with the earliest finish time
        machines[min_index][machine_indices[min_index]].machine_id = min_index + 1;
        machines[min_index][machine_indices[min_index]].task_id = tasks[i].task_id;
        machines[min_index][machine_indices[min_index]].start_time = tasks[i].start_time;
        machines[min_index][machine_indices[min_index]].finish_time = tasks[i].finish_time;
        machine_indices[min_index]++;
    }

    // Print tasks assigned to each machine
    for (int i = 0; i < num_machines; i++) {
        printf("\nMachine %d Schedule:\n", i + 1);
        printf("Task ID\tStart Time\tFinish Time\n");
        for (int j = 0; j < machine_indices[i]; j++) {
            printf("%d\t%d\t\t%d\n", machines[i][j].task_id, machines[i][j].start_time, machines[i][j].finish_time);
        }
    }
    
    return 0;
}
