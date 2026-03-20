#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *data = (int *)malloc(100 * sizeof(int));
    data[100] = 0;
    data[87] = 1;
    data[67] = 98;
    free(data);
    printf("the data %d %d %d\n", data[100], data[87], data[67]);
    return 1;
}