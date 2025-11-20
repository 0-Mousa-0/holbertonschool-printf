#include "main.h"

/* Add character to buffer */
int buf_add(char *buf, int *idx, char c)
{
    if (*idx == BUF_SIZE)
    {
        if (write(1, buf, *idx) == -1)
            return -1;
        *idx = 0;
    }

    buf[(*idx)++] = c;
    return 1;
}

/* Flush buffer */
int buf_flush(char *buf, int *idx)
{
    if (*idx > 0)
    {
        if (write(1, buf, *idx) == -1)
            return -1;
        *idx = 0;
    }
    return 1;
}
