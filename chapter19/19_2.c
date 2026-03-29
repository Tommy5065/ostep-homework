#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <immintrin.h>
#include <sys/time.h>

#define PAGE_SIZE 4096
#define handle_error_en(en, msg) \
    do                           \
    {                            \
        errno = en;              \
        perror(msg);             \
        exit(EXIT_FAILURE);      \
    } while (0);

int jump = PAGE_SIZE / sizeof(int);
struct timeval start, end;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "on right arguments");
        exit(1);
    }
    int s;
    cpu_set_t cpuset;
    pthread_t thread;

    thread = pthread_self(); // 获取当前运行的线程数据结构
    CPU_ZERO(&cpuset);
    CPU_SET(3, &cpuset);

    /*set CPU affinity of a thread*/
    s = pthread_setaffinity_np(thread, sizeof(cpuset), &cpuset);
    if (s != 0)
    {
        handle_error_en(s, "phtread_setaffinity_np");
    }
    /* Check the actual affinity mask assigned to the thread */
    s = pthread_getaffinity_np(thread, sizeof(cpuset), &cpuset);
    if (s != 0)
    {
        handle_error_en(s, "phtread_getaffinity_np");
    }

    int NUMBERPAGE = atoi(argv[1]);
    int NUMBER = atoi(argv[2]);
    int a[NUMBERPAGE * jump];

    gettimeofday(&start, NULL);
    for (int j = 0; j < NUMBER; ++j)
    {
        for (int i = 0; i < NUMBERPAGE * jump; i += jump)
        {
            a[i] += 1;
            // 删除缓存避免下次循环缓存干扰没有测试出TLB缺失
            _mm_clflush(&a[i]);
        }
    }
    gettimeofday(&end, NULL);
    printf("%lf, %.6ld,%.6ld \n", (((double)end.tv_usec - start.tv_usec) / NUMBER) / NUMBERPAGE, end.tv_usec, start.tv_usec);
    return 0;
}