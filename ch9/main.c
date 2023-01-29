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
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MEMSIZE u_int32_t  

/* valid commands list */
typedef enum Commands {
    RQ,     /* Request memory */
    RL,     /* Release memory */
    C,      /* Compact memory */
    STAT,   /* memory status */
    X       /* exit program */
} Commands; 

int main(int argc, char** argv) {

    /* memory size validation: still incomplete but good enough 
    for project purposes (no validation for 123a555) */
    if(argc > 2) {
        printf("[too many arguments passed]");
        return 1;
    } else if(argc < 1) {
        printf("[no arguments given]");
        return 1; 
    }

    int sizeCheck = atoi(argv[1]);
    if(!isdigit(argv[1][0])) {
        printf("[must enter numeric number]");
        return 1; 
    }

    if(sizeCheck < 0) {
        printf("[Non-positive integer given]");
        return 1; 
    }
    

    /* parse for the memory size given to the program */
    MEMSIZE memory = (int) strtol(argv[1], (char **)NULL, 10);
    printf("%i bytes of memory have been allocated\n", memory);

    /* main program loop */
    bool programEnd = false;
    while(!programEnd) {
        
        char input[2]; 
        printf("allocator>");
        scanf("%s", input);

        if(strcmp(input, "X") == 0) {
            programEnd = true;
            continue;
        } else if(strcmp(input, "RQ") == 0) {
            
        }

    }


    return 0; 
};



