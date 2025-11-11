/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */
/*
* Lab 10 - Signals
* Author: Spencer Jones
* CPE 2600 121
* Build using make
*/
/**
 * Modified by: Spencer Jones
 * 
 * Brief summary of modifications: No longer exits unless recieves sigkill
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    //exit(1);
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);
    printf("%d", getpid());
    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");   
        sleep(1);
    }

    return 0;
}