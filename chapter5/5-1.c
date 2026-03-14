#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int x = 100;
    printf("hello world (pid:%d) \n",(int) getpid());
    int rc = fork(); // 调用fork()创建新进程
    if (rc<0){ // fork() failed;exit
        fprintf(stderr,"fork failed\n");
        exit(1);
    } else if (rc == 0){
        printf("hello,I am child (pid:%d)\n",(int) getpid());
        printf("child read x = %d (pid:%d)\n",x,(int) getpid());
        x = 200;
        printf("child change x = %d\n",x);
    } else {
        x = 300;
        printf("hello,I am father of %d (pid:%d)\n",rc,(int) getpid());
        printf("father change x = %d\n",x);
    }
}