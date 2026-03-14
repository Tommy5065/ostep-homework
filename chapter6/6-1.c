#include <stdio.h>
#include <sys/time.h>

int main(){
    struct timeval start,end;
    for (int t=0;t<12;t++){
        gettimeofday(&start,NULL);
        gettimeofday(&end,NULL);
        printf("total time: %ld\n",end.tv_usec-start.tv_usec);
        printf("%ld %ld\n",start.tv_usec,end.tv_usec);
    }
}