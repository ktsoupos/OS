#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *file = fopen("pids.txt", "w");

    if (!file) {
        printf("Failed to open file\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid > 0) { // Parent
        fprintf(file, "Parent PID: %d\n", getpid());
        fclose(file);
        wait(NULL);
    } else if (pid == 0) { // Child
        fprintf(file, "Child PID: %d\n", getpid());
        fclose(file);
    } else {
        printf("Fork failed!\n");
    }

    return 0;
}
