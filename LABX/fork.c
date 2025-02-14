#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        } else if (pid > 0) {
            wait(NULL); // Wait for child to finish
        } else {
            printf("Fork failed!\n");
        }
    }
    return 0;
}
