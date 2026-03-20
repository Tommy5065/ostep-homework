#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *data = (int *)malloc(100 * sizeof(int));
    free(data + 80);
    printf("the data %d %d %d\n", data[100], data[87], data[67]);
    return 1;
}