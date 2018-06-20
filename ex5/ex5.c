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
    
    return 0;
}
