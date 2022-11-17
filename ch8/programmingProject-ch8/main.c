/*
 * author: amir kamalian
 * date:   nov 16, 2022
 * description: chapter 8 programming project.  Implementing Bankers 
 *              algorithm.
 * 
 * 
 */


#include <stdio.h>

/* macro definitions */
#define NUMBER_OF_CUSTOMERS 5
#define NUMBER_OF_RESOURCES 4

/* function prototypes for requesting and releasing resources */
int request_resources(int customer_num, int request[]);

int release_resources(int customer_num, int release[]);


int main(int argc, char** argv) {
    /* data structures used for bankers algorithm */
    /* the number of resources that are available */
    int available[NUMBER_OF_RESOURCES];

    /* the max demand of each customer (i.e. the maximum 
     * number of resources each process can have) */
    int maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
    
    /* the amount of resources currently allocated to each 
     * customer (i.e. process) */
    int allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

    /* the remaining need of each customer (how many resources 
     * each process needs to complete its job) */
    int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];



    return 0;
};



