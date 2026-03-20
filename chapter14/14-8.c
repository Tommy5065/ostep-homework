#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *data = (int *)malloc(4 * sizeof(int));
    data[0] = 26;
    int *data1 = (int *)realloc(data, 20);
    data1[14] = 89;
    printf("the data %d %d\n", data1[14], data1[0]);
    // free(data);
    free(data1);
    return 1;
}