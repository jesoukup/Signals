////////////////////////////////////////////////////////////////////////////////
// Main File:        sendsig.c
// This File:        sendsig.c
// Other Files:      intdate.c division.c
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
#include <stdlib.h>

/* This main function sends SIGUSR1 and SIGINT signals to other
 * programs depending on the command line arguments chosen by
 * the user. The first command line argument choses what signal
 * to be sent out. The second choses what PID to send it to.
 * "-u" sends a SIGUSR1 signal
 * "-i" sends a SIGINT signal
 */
int main(int argc, char *argv[]) {
    if (strcmp(argv[1], "-u") == 0) {
        kill(atol(argv[2]), SIGUSR1);
    }
    if (strcmp(argv[1], "-i") == 0) {
        kill(atol(argv[2]), SIGINT);
    }
    return 0;
}
