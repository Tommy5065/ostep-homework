#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    printf("hello world (pid:%d) \n",(int) getpid());
    int rc = fork(); // 调用fork()创建新进程
    if (rc<0){ // fork() failed;exit
        fprintf(stderr,"fork failed\n");
        exit(1);
    } else if (rc == 0){ // child (new process)
        int wc = wait(NULL);
        printf("child (pid:%d) (wc:%d)\n",(int) getpid(),wc);
    } else {  // parent goes down this path (main)
        int wc = wait(NULL);
        printf("father (pid:%d) (wc:%d)\n",(int) getpid(),wc);
    }
    return 0;
}