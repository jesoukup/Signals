////////////////////////////////////////////////////////////////////////////////
// Main File:        division.c
// This File:        division.c
// Other Files:      intdate.c sendsig.c
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

int counter = 0;  // Keeps track of successful divisions

/* This function catches the signal sent when a division by zero is attempted 
 * and prints the amount of successful divisions followed by exiting the program.
 */
void arithmeticHandler(int sig) {
    printf("Error: a division by 0 operation was attempted.\n");
    printf("Total number of operations completed successfully: %d\n", counter);
    printf("The program will be terminated.\n");
    exit(0);
}

/* This function catches the signal sent when Ctrl+C is used by the user and
 * prints the amount of successful divisions followed by exiting the program.
 */
void sigintHandler(int sig) {
    printf("\n");
    printf("Total number of operations completed successfully: %d\n", counter);
    printf("The program will be terminated.\n");
    exit(0);
}

/* This main function runs an infinite loop to calculate the division between
 * two user inputted numbers.
 */
int main() {
    // Initialize sigaction struct for sigintHandler
    struct sigaction ac;
    memset (&ac, 0, sizeof(ac));
    ac.sa_handler = sigintHandler;
    sigaction(SIGINT, &ac, NULL);

    // Initialize the sigaction struct for arithmeticHandler
    struct sigaction act;
    memset (&act, 0, sizeof(act));
    act.sa_handler = arithmeticHandler;
    sigaction(SIGFPE, &act, NULL);

    // Infinite loop to divide inputted ints
    while (1) {
        char firstInt[10];
        char secondInt[10];
        printf("Enter first integer: ");
        fgets(firstInt, 10, stdin);
        printf("Enter second integer: ");
        fgets(secondInt, 10, stdin);
        int intOne = atoi(firstInt);
        int intTwo = atoi(secondInt);
        int quotient = intOne / intTwo;
        int remainder = intOne % intTwo;
        printf("%d / %d is %d with a remainder of %d\n", 
        intOne, intTwo, quotient, remainder);
        counter += 1;
    }
    return 0;
}
