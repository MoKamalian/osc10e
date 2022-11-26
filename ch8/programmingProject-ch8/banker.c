/*
 * author: amir kamalian
 * date:   nov 19, 2022
 * 
 * 
 * 
*/


#include "banker.h"


/* request function: will check to see if the 
    request will leave the system in a safe 
    state.  Request is denied if safe state is 
    not permitted.  Note that all arrays should 
    be the same length. 
        customer_num: i.e. the row 
    
    Returns 1 (i.e. true) if the state is safe,
    returns 0 if there state is unsafe (not 
    necessarily deadlock) */
int request_resources(int customer_num, int* request, int* available, int** need, int** allocation) {
    /* determine weather the request is greater than the max that 
    can be requested or if it is greater than the available resources */
    int length = sizeof(request) / sizeof(request[0]);
    for(int i=0; i<length; i++) {
        if(request[i] >= need[customer_num][i] || request[i] > available[i]) {
            return 1;
        }
    }


    /* main implementation of safety algorithm */
    int* work = available;
    bool finish[NUMBER_OF_CUSTOMERS];
    for(int i=0; i<NUMBER_OF_CUSTOMERS; i++) {
        finish[i] = false;
    }
    
    /* loop through the number of processes and determine if there 
    are enough available resources to allocate to finish execution of the process */
    for(int i=0; i<NUMBER_OF_CUSTOMERS; i++) {

        for(int j=0; j<NUMBER_OF_RESOURCES; j++) {

            if(finish[i] == false && need[i][j] < work[j]) {
                work[j] = work[j] + allocation[j];
                finish[i] = true;
            } 
        }
    }

    for(int i=0; i<NUMBER_OF_CUSTOMERS; i++) {
        if(finish[i] == false) {
            return 0;
        }
    }
    return 1;

    /* if the request is okay, allocate the resource by modifying the 
    appropriate arrays. */
    /*for(int i=0; i<length; i++) {
        available[i] = available[i] - request[i];
        allocation[customer_num][i] = allocation[customer_num][i] + request[i];
        need[customer_num][i] = need[customer_num][i] - request[i];
    }
    */
    

    return 0;
};


/* function used to release resources from a process */
int release_resource(int customer_number, int release[], int* available, int** allocated) {
    /* change the resources allocated to adjust what was released */
    for(int i=0; i<NUMBER_OF_RESOURCES; i++) {
        allocated[customer_number][i] -= release[i];
    }

    /* release back the resources into the available pool */
    for(int i=0; i<NUMBER_OF_RESOURCES; i++) {
        available[i] += release[i];
    }

};