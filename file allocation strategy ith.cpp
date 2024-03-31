#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_BLOCKS 10
#define BLOCK_SIZE 100

void simulateFileAccess(int indexBlock[]) {
    char buffer[BLOCK_SIZE];
    bool endOfFile = false;
    int blockIndex = 0;

    printf("Simulating file access...\n");

    while (!endOfFile) {
        int blockAddress = indexBlock[blockIndex];
        if (blockAddress == -1) {
            endOfFile = true;
            break;
        }

        printf("Reading block %d...\n", blockAddress);
        
        printf("Processing block %d content...\n", blockAddress);
        printf("Block content: Placeholder data for block %d\n", blockAddress);

        blockIndex++;

        if (blockIndex >= NUM_BLOCKS)
            endOfFile = true;
    }

    printf("End of file access simulation.\n");
}

int main() {
    int indexBlock[NUM_BLOCKS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1}; 

    simulateFileAccess(indexBlock); 

    return 0;
}
