#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_RECORD_SIZE 100
#define MAX_BUFFER_SIZE 10

void simulateFileAccess(FILE *file) {
    char buffer[MAX_RECORD_SIZE];
    char record[MAX_RECORD_SIZE];
    int bufferIndex = 0;
    int recordIndex = 0;
    bool endOfFile = false;

    printf("Simulating file access...\n");

    while (!endOfFile) {
        char ch;
        int bytesRead = 0;
        while ((ch = fgetc(file)) != '\n' && ch != EOF && bytesRead < MAX_RECORD_SIZE) {
            record[bytesRead++] = ch;
        }
        record[bytesRead] = '\0'; 

        printf("Read record: %s\n", record);
        
        for (int i = 0; i < bytesRead; i++) {
            buffer[bufferIndex++] = record[i];
            if (bufferIndex == MAX_BUFFER_SIZE) {
                printf("Buffer full, processing buffer: %s\n", buffer);
                bufferIndex = 0;
            }
        }

        if (ch == EOF)
            endOfFile = true;
    }

    if (bufferIndex > 0) {
        printf("End of file reached, processing remaining buffer: %s\n", buffer);
    }

    printf("End of file access simulation.\n");
}

int main() {
    FILE *file = fopen("file.txt", "r"); 

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    simulateFileAccess(file); 

    fclose(file);
    return 0;
}
