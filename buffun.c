#include "main.h"

int buf_add(char *buf, int *idx, char c)
{
    if (*idx >= BUF_SIZE)
        return -1;
    buf[(*idx)++] = c;
    return 1;
}

int buf_flush(char *buf, int *idx)
{
    if (*idx > 0)
    {
        write(1, buf, *idx);
        *idx = 0;
    }
    return 1;
}
