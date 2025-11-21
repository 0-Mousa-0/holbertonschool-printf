#include "main.h"

#define BUFFER_SIZE 1024

/* Forward declaration to avoid implicit declaration */
void buff_flush(char *buff, int *buff_i);

/* Add character to buffer */
void buff_push(char *buff, int *buff_i, char c)
{
    if (*buff_i >= BUFFER_SIZE)
        buff_flush(buff, buff_i);

    buff[(*buff_i)++] = c;
}

/* Flush buffer to stdout */
void buff_flush(char *buff, int *buff_i)
{
    if (*buff_i > 0)
    {
        write(1, buff, *buff_i);
        *buff_i = 0;
    }
}

