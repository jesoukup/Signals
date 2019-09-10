////////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File:        intdate.c
// Other Files:      sendsig.c division.c
// Semester:         CS 354 Spring 2018
// Lecture:          001
//
// Author:           Joseph Soukup
// Email:            jsoukup2@wisc.edu
// CS Login:         soukup
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          none
//                   
//
// Online sources:   none
//                    
//                   
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// Initialize alarm time
int seconds = 3; 

// Initialize global counter to keep track of 
// amount of times program receives SIGUSR1
int counter = 0;

/* This function catches the alarm signal and prints the PID and time
 */
void alarmHandler(int sig) {
    // Print time and PID
    time_t curtime;
    time(&curtime);
    printf("PID: %d", getpid());
    printf(" | Current time: %s", ctime(&curtime));

    // Call alarm
    alarm(seconds);
}
/* This function catches the SIGUSR1 signal and increments the counter.
 */
void sigusr1Handler(int sig) {
    counter += 1;
    printf("SIGUSR1 caught!\n");
}

/* This function catches the SIGINT signal, prints the amount of times
 * a SIGUSR1 signal was caught, and exits the program.
 */
void sigintHandler(int sig) {
    printf("\n");
    printf("SIGINT received.\n");
    printf("SIGUSR1 was received %d times. Exiting now.\n", counter);
    exit(0);
}

/* This main function runs an infinite loop with an alarm that is called
 * every 3 seconds.
 */
int main() {
    printf("Pid and time will be printed every 3 seconds.\n");
    printf("Enter ^C to end the program.\n");

    // Initialize sigaction struct for alarmHandler
    struct sigaction act;
    memset (&act, 0, sizeof(act));
    act.sa_handler = alarmHandler;
    sigaction(SIGALRM, &act, NULL);

    // Initialize sigaction struct for sigusr1Handler
    struct sigaction action;
    memset (&action, 0, sizeof(action));
    action.sa_handler = sigusr1Handler;
    sigaction(SIGUSR1, &action, NULL);

    // Initialize sigaction struct for sigintHandler
    struct sigaction ac;
    memset (&ac, 0, sizeof(ac));
    ac.sa_handler = sigintHandler;
    sigaction(SIGINT, &ac, NULL);

    // Call alarm
    alarm(seconds);

    // Infinite loop
    while (1) {
    }
    return 0;
}
