/*方案因为一次循环就很快，我们执行N次循环，算出执行一次循环时间，再用一次循环的意思/假设的页数，得到每个页的平均访问开销*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define PAGE_SIZE 4096  /*页大小:4KB*/
#define NUMBERPAGE 1024 /*假设TLB的大小*/
#define NUMBER 30000000
int jump = PAGE_SIZE / sizeof(int); /*1页能存多少个Int类型*/

struct timeval start, end;

int main(int argc, char *argv[])
{
    int a[NUMBERPAGE * jump];
    gettimeofday(&start, NULL);
    for (int j = 0; j < NUMBER; ++j)
    {
        for (int i = 0; i < NUMBERPAGE * jump; i += jump)
        {
            a[i] += 1;
        }
    }
    gettimeofday(&end, NULL);
    printf("the all times to read TLB :%.6f, %d,%d", ((double)end.tv_sec - start.tv_sec) / NUMBER, end.tv_sec, start.tv_sec);
    return 0;
}
