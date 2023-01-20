/*
 * author: amir kamalian
 * date:   jan 17 2023
 *
*/

/*
 * cases: 
 * 1. Program must request contiguous block of memory 
 * 2. Release contiguous block of memory 
 * 3. Compact unused holes of memory into single block 
 * 4. Report the regions of free and allocated memory 
 * 
*/



#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE int 

/* valid commands list */
typedef enum Commands {
    RQ,     /* Request memory */
    RL,     /* Release memory */
    C,      /* Compact memory */
    STAT,   /* memory status */
    X       /* exit program */
} Commands; 

int main(int argc, char** argv) {


    /* parse for the memory size given to the program */
    MEMSIZE memory = (int) strtol(argv[1], (char **)NULL, 10);



    return 0; 
};



