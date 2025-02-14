#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig) {
    printf("Child received signal %d from parent!\n", sig);
}

int main() {
    pid_t pid = fork();

    if (pid > 0) { // Parent process
        sleep(1); // Ensure child sets up signal handler
        kill(pid, SIGUSR1);
        wait(NULL);
    } else if (pid == 0) { // Child process
        signal(SIGUSR1, handle_signal);
        pause(); // Wait for signal
    } else {
        printf("Fork failed!\n");
    }

    return 0;
}
