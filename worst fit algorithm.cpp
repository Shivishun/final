#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESS 100

int main() {
    int num_blocks, num_processes, i, j;
    int block_sizes[MAX_BLOCKS], process_sizes[MAX_PROCESS];
    int allocation[MAX_PROCESS];

    printf("Enter the number of memory blocks: ");
    scanf("%d", &num_blocks);

    printf("Enter the sizes of memory blocks:\n");
    for (i = 0; i < num_blocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block_sizes[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the sizes of processes:\n");
    for (i = 0; i < num_processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &process_sizes[i]);
    }

    for (i = 0; i < num_processes; i++) {
        int worst_fit_index = -1;
        for (j = 0; j < num_blocks; j++) {
            if (block_sizes[j] >= process_sizes[i]) {
                if (worst_fit_index == -1 || block_sizes[j] > block_sizes[worst_fit_index]) {
                    worst_fit_index = j;
                }
            }
        }

        if (worst_fit_index != -1) {
            allocation[i] = worst_fit_index;
            block_sizes[worst_fit_index] -= process_sizes[i];
        } else {
            allocation[i] = -1;
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t", i + 1, process_sizes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }

    return 0;
}
