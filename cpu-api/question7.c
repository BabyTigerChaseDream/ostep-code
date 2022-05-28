#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
		// child: redirect standard output to a file
		// close(STDOUT_FILENO); 
		printf("hello, I am Child ");
    } else {
        // parent goes down this path (original process)
		printf("Bye , I am Parent ");
    }
    return 0;
}