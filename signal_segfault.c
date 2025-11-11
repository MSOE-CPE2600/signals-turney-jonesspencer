/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
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
 * Brief summary of modifications: registers a segfault handler and will catch and loop segfault until terminated
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void segv_handler(int signum)
{
    printf("Caught SIGSEGV (%d): segmentation fault\n", signum);
}

int main(int argc, char *argv[])
{
    if (signal(SIGSEGV, segv_handler) == SIG_ERR) {
        perror("signal");
        return 1;
    }

    printf("About to dereference NULL pointer...\n");
    int *i = NULL;
    printf("The value of i is: %d\n", *i);  /* generates SIGSEGV repeatedly */
    printf("This line will never be reached.\n");

    return 0;
}
