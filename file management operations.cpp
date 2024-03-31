#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main() {
 int fd = creat("test.txt", 0644);
 if (fd < 0) {
 printf("Error creating file\n");
 return 1;
 }

 fd = open("test.txt", O_RDWR);
 if (fd < 0) {
 printf("Error opening file\n");
 return 1;
 }

 char data[] = "Hello, World!";
 if (write(fd, data, sizeof(data)) < 0) {
 printf("Error writing to file\n");
 return 1;
 }

 char buffer[100];
 if (read(fd, buffer, sizeof(buffer)) < 0) {
 printf("Error reading from file\n");
 return 1;
 }
 printf("Data: %s\n", buffer);

 if (close(fd) < 0) {
 printf("Error closing file\n");
 return 1;
 }

 if (unlink("test.txt") < 0) {
 printf("Error deleting file\n");
 return 1;
 }

 return 0;
}