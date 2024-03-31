#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    fd = creat("file.txt", 0644);
    if (fd < 0) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    printf("File created successfully.\n");

    write(fd, "Hello, this is a test file.\n", 28);

    close(fd);

    fd = open("file.txt", O_RDWR);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    read(fd, buffer, sizeof(buffer));
    printf("Content read from file: %s\n", buffer);

    lseek(fd, 0, SEEK_SET);

    write(fd, "This is additional content.\n", 28);

    close(fd);

    if (unlink("file.txt") < 0) {
        perror("Error deleting file");
        exit(EXIT_FAILURE);
    }
    printf("File deleted successfully.\n");

    return 0;
}
