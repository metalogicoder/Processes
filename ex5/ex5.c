// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16 // size of messages

// messages to be written
char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main()
{
    // Your code here

    // buffer for read function
    char inbuf[MSGSIZE];
    // array for read(i = [0]) write(i = [1]) data
    int p[2]; 

    // make sure that pipe is established
    if (pipe(p) < 0) {
      fprintf(stderr, "pipe failed\n");
      exit(1);
    }

    // write messages to array
    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);

    int rc = fork();
    
    if (rc < 0) { // Fail
      fprintf(stderr, "fork failed\n");
      exit(1);
    } else if (rc == 0) { // Child
      puts("- Child -");
      for (int i = 0; i < 3; i++) {
        // read messages from array
        read(p[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
      }
    }
    
    return 0;
}
