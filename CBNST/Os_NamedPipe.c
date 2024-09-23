#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_NAME "my_named_pipe"
#define BUFFER_SIZE 256

int main() {
    // Create a named pipe (FIFO)
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process: Take input from the user and write it to the pipe
        char user_input[BUFFER_SIZE];
        int fd = open(FIFO_NAME, O_WRONLY);
        if (fd == -1) {
            perror("open for write");
            exit(EXIT_FAILURE);
        }

        printf("Child: Enter a string: ");
        fgets(user_input, sizeof(user_input), stdin);

        // Remove newline character from fgets (if present)
        size_t len = strlen(user_input);
        if (user_input[len - 1] == '\n') {
            user_input[len - 1] = '\0';
        }

        // Write the user input to the pipe
        write(fd, user_input, strlen(user_input) + 1);  // Include null terminator
        close(fd);
        printf("Child: Sent string to parent.\n");
    } else {
        // Parent process: Read the string from the pipe and determine its size
        char buffer[BUFFER_SIZE];
        int fd = open(FIFO_NAME, O_RDONLY);
        if (fd == -1) {
            perror("open for read");
            exit(EXIT_FAILURE);
        }

        // Read the string from the pipe
        read(fd, buffer, sizeof(buffer));
        printf("Parent: Received string: %s\n", buffer);

        // Determine the size of the string (including the null terminator)
        size_t byte_size = strlen(buffer) + 1;
        printf("Parent: The size of the string in bytes is: %zu bytes\n", byte_size);

        close(fd);
    }

    // Remove the named pipe after use
    unlink(FIFO_NAME);
    return 0;
}
