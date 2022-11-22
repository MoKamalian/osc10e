/*
 * author: amir kamalian
 * date:   nov 19, 2022
 * 
 * 
 * 
 */


#pragma once


/* macro definitions */
#define NUMBER_OF_CUSTOMERS 5
#define NUMBER_OF_RESOURCES 4

/* function prototypes for requesting and releasing resources */
int request_resources(int customer_num, int* request, int* available, int* need[], int** allocation);

int release_resources(int customer_num, int release[]);


