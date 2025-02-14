#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char msg[] = "Hello from parent!";
    char buffer[50];

    if (pipe(fd) == -1) {
        printf("Pipe failed\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid > 0) { // Parent process
        close(fd[0]); // Close reading end
        write(fd[1], msg, strlen(msg) + 1);
        close(fd[1]);
    } else if (pid == 0) { // Child process
        close(fd[1]); // Close writing end
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    } else {
        printf("Fork failed!\n");
    }

    return 0;
}
