// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

int main(int argc, char* argv[])
{
    // Your code here
    int rc = fork();

    if (rc < 0) { // Fail
      fprintf(stderr, "fork failed\n");
      exit(1);
    } else if (rc == 0) { // Child
      puts("Hello");
    } else { // Parent
      int wc = waitpid(rc, NULL, 0);
      puts("Goodbye");
    }

    return 0;
}
