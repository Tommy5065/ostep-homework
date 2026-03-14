#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <sched.h>

int main(){
    int oneCPU = 0;
    cpu_set_t  set;
    int pip1[2];
    int pip2[2];
    struct timeval start,end;
    char test[]={'h','e','l','l','p','\0'};

    int p1 = pipe(pip1);
    int p2 = pipe(pip2);

    if (p1<0 || p2<0){
        fprintf(stderr,"pipe faile");
        exit(1);
    }

    CPU_ZERO(&set);
    CPU_SET(oneCPU,&set);

    if (sched_setaffinity(getpid(),sizeof(set),&set)==-1){
        fprintf(stderr,"sched_setaffinity fail");
        exit(1);
    } else{
        int rc = fork();
        for(int i=0;i<10;i++){
            if (rc < 0){
            fprintf(stderr,"create fork fail");
            exit(1);
        } else if (rc==0&&sched_setaffinity(rc,sizeof(set),&set)!=-1){
            read(pip1[0],test,strlen(test));
            gettimeofday(&end,NULL);
            printf("chang parent to child take %ld\n",end.tv_usec-start.tv_usec);
            gettimeofday(&start,NULL);
            write(pip2[1],test,strlen(test));
        } else { // parent goes down
            gettimeofday(&start,NULL);
            write(pip1[1],test,strlen(test));
            read(pip2[0],test,strlen(test));
            gettimeofday(&end,NULL);
            printf("chang child to parent take %ld\n",end.tv_usec-start.tv_usec);
        }
        }
    }

}