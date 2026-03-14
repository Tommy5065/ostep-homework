#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int rc = vfork(); // 让子进程先运行
    if (rc<0){ // fork() failed;exit
        fprintf(stderr,"fork failed\n");
        exit(1);
    } else if (rc == 0){
        printf("child hello (pid:%d)\n",(int) getpid());
    } else {
        printf("goodbye,I am father of %d (pid:%d)\n",rc,(int) getpid());
    }
}