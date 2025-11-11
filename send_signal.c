/**
 * File: send_signal.c
 * Modified by: Spencer Jones
 * Brief summary of program: sends a signal to a given pid
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        return 1;
    }

    unsigned int pid = (unsigned int)atoi(argv[1]);

    srand((unsigned int)time(NULL));
    int value = rand();

    union sigval sv;
    sv.sival_int = value;

    printf("Sending SIGUSR1 with value %d to PID %d\n", value, pid);

    if (sigqueue(pid, SIGUSR1, sv) == -1) {
        perror("sigqueue");
        return 1;
    }

    return 0;
}