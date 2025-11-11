/**
 * File: recv_signal.c
 * Modified by: Spencer Jones
 * 
 * Brief summary of program:
 * Waits to recieve a signal and prints the signal with the data send and from which pid
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

static void usr1_handler(int sig, siginfo_t *info, void *ucontext)
{
    (void)ucontext;
    int value = info->si_value.sival_int;
    printf("Received SIGUSR1 (%d) with sival_int = %d from PID %d\n",
           sig, value, info->si_pid);
}

int main(void)
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = usr1_handler;
    sa.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Receiver PID: %d\n", getpid());
    printf("Waiting for SIGUSR1 with data...\n");

    while (1) {
        pause();
    }

    return 0;
}
