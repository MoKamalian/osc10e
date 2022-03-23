/**
 * Simple shell interface program.
 *
 * Operating System Concepts - Tenth Edition
 * Copyright John Wiley & Sons - 2018
 */



#include <stdio.h>
#include <unistd.h>

/* the maximum chars for the command is 80 */
#define MAX_LINE 80 
/* this is the main program that will run to ask the user for input in the 
* command line terminal */
int main(void) {
	char *args[MAX_LINE / 2 + 1];
	int should_run = 1;
	/* as long as should_run is 1 the program will continue to ask user for input */
	char input[50];
	while(should_run) {
		printf("osh>");
		fgets(input, 50, stdin);
		printf("%s", input);
		should_run = 0;
		fflush(stdout);

		/**
         	 * After reading user input, the steps are:
         	 * (1) fork a child process
         	 * (2) the child process will invoke execvp()
         	 * (3) if command included &, parent will invoke wait()
         	 */
		
	} 

	
	//execvp(char *command, char params[]);

	return 0;
}