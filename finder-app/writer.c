/*
3. Write a C application “writer” (finder-app/writer.c)  which can be used as an alternative to the “writer.sh” test script created in assignment1 and using File IO as described in LSP chapter 2.  See the Assignment 1 requirements for the writer.sh test script and these additional instructions:

    One difference from the write.sh instructions in Assignment 1:  You do not need to make your "writer" utility create directories which do not exist.  You can assume the directory is created by the caller.

    Setup syslog logging for your utility using the LOG_USER facility.

    Use the syslog capability to write a message “Writing <string> to <file>” where <string> is the text string written to file (second argument) and <file> is the file created by the script.  This should be written with LOG_DEBUG level.

    Use the syslog capability to log any unexpected errors with
    LOG_ERR level.
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
	syslog(LOG_ERR, "Incorrect number of arguments expected 2 got %d. Usage: writer filesdir searchstr", argc - 1);
	exit(1);
    }

    char *writefile=argv[1];	
    char *writestr = argv[2];

    int fd;
    fd = open (writefile, O_WRONLY|O_CREAT|O_TRUNC, S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH);
    if (fd == -1) {
	syslog(LOG_ERR, "Could not open file %s", writefile);
    }

    ssize_t nr;
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
    nr = write (fd, writestr, strlen (writestr));
    if (nr == -1) {
	syslog(LOG_ERR, "Could not write in file");
    }

}
