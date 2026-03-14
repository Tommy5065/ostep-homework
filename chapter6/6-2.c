#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
    int fd = open("./6-2.out",O_CREAT|O_RDONLY);
    char chu[25];
    struct timeval start,end;
    if (fd < 0){
        fprintf(stderr,"open failed.\n");
        exit(1);
    }
    for (int i=0;i<10;i++){
        gettimeofday(&start,NULL);
        read(fd,chu,3);
        gettimeofday(&end,NULL);
        printf("total time %ld\n",end.tv_usec-start.tv_usec);
    }
    close(fd);
    return 0;


}