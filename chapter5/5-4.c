#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    printf("hello world (pid:%d) \n",(int) getpid());
    int rc = fork(); 
    if (rc<0){ 
        fprintf(stderr,"fork failed\n");
        exit(1);
    } else if (rc == 0){ // child (new process)
        printf("hello,I am child (pid:%d)\n",(int) getpid());
        char *myargs[3];
        myargs[0] = strdup("ls"); 
        myargs[1] = "-l"; 
        myargs[2] = NULL; 

        // char *env[] = {NULL};
        execvp(myargs[0],myargs); 
        printf("this shouldn't print pout");
    } else {  // parent goes down this path (main)
        printf("hello,I am father of %d (pid:%d)\n",rc,(int) getpid());
    }
    return 0;
}