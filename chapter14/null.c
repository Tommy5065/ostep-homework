#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x = (int *)malloc(sizeof(int)); // 注意此时sizeof是操作符，不是函数调用，因为在编译时就能算出字节大小，不需要运行计算;
    x = NULL;
    free(x);
    return 1;
}