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
    
    Returns 1 if the resources are either unavailable 
    or thread exceeds max request.  Return 0 when 
    the resources have been allocated. */
int request_resources(int customer_num, int* request, int* available, int** need, int** allocation) {
    /* determine weather the request is greater than the max that 
    can be requested or if it is greater than the available resources */
    int length = sizeof(request) / sizeof(request[0]);
    for(int i=0; i<length; i++) {
        if(request[i] >= need[customer_num][i] || request[i] > available[i]) {
            return 1;
        }
    }

    /* if the request is okay, allocate the resource by modifying the 
    appropriate arrays. */
    for(int i=0; i<length; i++) {
        available[i] = available[i] - request[i];
        allocation[customer_num][i] = allocation[customer_num][i] + request[i];
        need[customer_num][i] = need[customer_num][i] - request[i];
    }
    

    return 0;
};
