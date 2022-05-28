#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

int
main(int argc, char *argv[])
{
    int rc = fork();
    int fd = open("/tmp/hw2.output", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    assert(fd >= 0);
    char buffer[30];
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
		sprintf(buffer, "hello from child \n");
		int rfd = write(fd, buffer, strlen(buffer));
		assert(rfd == (strlen(buffer)));
		fsync(fd);
		close(fd);		

    } else {
        // parent goes down this path (original process)
        // int wc = wait(NULL);
		// assert(wc >= 0);
		sprintf(buffer, "parent is saying hello  \n");
		int rfd = write(fd, buffer, strlen(buffer));
		assert(rfd == (strlen(buffer)));
		fsync(fd);
		close(fd);		
    }
    return 0;
}
