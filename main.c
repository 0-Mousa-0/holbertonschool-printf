#include <stdio.h>
#include "main.h"

int main(void)
{
    char buffer[1024];
    int idx = 0;

    unsigned int n = 123;

    int count = print_base(buffer, &idx, n, 10, "0123456789");

    buf_flush(buffer, &idx);

    buffer[idx] = '\0';

    printf("Buffer content: %s\n", buffer);
    printf("Characters written: %d\n", count);

    return 0;
}
