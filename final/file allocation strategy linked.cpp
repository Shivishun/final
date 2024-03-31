#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLOCK_SIZE 100

typedef struct Block {
    char data[BLOCK_SIZE];
    struct Block *next;
} Block;

void simulateFileAccess(Block *firstBlock) {
    bool endOfFile = false;
    Block *currentBlock = firstBlock;

    printf("Simulating file access...\n");

    while (!endOfFile) {
        printf("Reading block...\n");
        
        printf("Processing block content...\n");
        printf("Block content: Placeholder data for the block\n");

        if (currentBlock->next != NULL) {
            currentBlock = currentBlock->next;
        } else {
            endOfFile = true; 
        }
    }

    printf("End of file access simulation.\n");
}
void freeBlocks(Block *firstBlock) {
    Block *currentBlock = firstBlock;
    while (currentBlock != NULL) {
        Block *temp = currentBlock;
        currentBlock = currentBlock->next;
        free(temp);
    }
}

int main() {
    Block *firstBlock = (Block *)malloc(sizeof(Block));
    firstBlock->next = (Block *)malloc(sizeof(Block));
    firstBlock->next->next = (Block *)malloc(sizeof(Block));
    firstBlock->next->next->next = NULL; 

    simulateFileAccess(firstBlock); 

    freeBlocks(firstBlock); 

    return 0;
}
