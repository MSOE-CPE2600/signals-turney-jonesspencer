/**
 * File: Signal_alarm.c
 * Modified by: Spencer Jones
 * 
 * Brief summary of program: Sets alarm for 5 seconds after recieving a signal
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void alarm_handler(int signum)
{
    printf("Received SIGALRM (%d)\n", signum);
}

int main(void)
{
    if (signal(SIGALRM, alarm_handler) == SIG_ERR) {
        perror("signal");
        return 1;
    }

    printf("PID: %d\n", getpid());
    printf("Setting alarm for 5 seconds...\n");
    alarm(5);

    /* Wait for signals */
    while (1) {
        pause();
    }

    return 0;
}
