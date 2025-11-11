/**
 * File: signal_sigaction.c
 * Modified by: Spencer Jones
 * 
 * Brief summary of program: Registers a handler for siguser1, prints pid of caller and exits
 */
/*
* Lab 10 - Signals
* Author: Spencer Jones
* CPE 2600 121
* Build using make
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

static void usr1_handler(int sig, siginfo_t *info, void *ucontext)
{
    (void)ucontext; 
    printf("Received SIGUSR1 (%d) from PID %d\n", sig, info->si_pid);
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

    printf("PID: %d\n", getpid());
    printf("Waiting for SIGUSR1...\n");

    while (1) {
        pause();
    }

    return 0;
}