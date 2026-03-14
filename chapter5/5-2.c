#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    printf("hello world (pid:%d) \n",(int) getpid());
    int rc = fork(); 
    if (rc<0){ // fork() failed;exit
        fprintf(stderr,"fork failed\n");
        exit(1);
    } else if (rc == 0){ // child : redirect standard output to a file
        close(STDOUT_FILENO); // avaliable file description
        open("./5-2.output",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU); 
        printf("writen by child (PID:%d)",(int) getpid());
    } else {  // parent goes down this path (main)
        close(STDOUT_FILENO);
        open("./5-2.output",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
        printf("hello,I am father of %d (pid:%d)\n",rc,(int) getpid());
    }
    return 0;
}