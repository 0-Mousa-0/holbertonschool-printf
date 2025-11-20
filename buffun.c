#include "main.h"

/**
 * buff_push - adds char to buffer; flushes when full
 */
int buff_push(char c, char *buff, int *buff_i)
{
    if (*buff_i >= 1024)
        buff_flush(buff, buff_i);

    buff[(*buff_i)++] = c;
    return 1;
}

/**
 * buff_flush - writes buffer content to stdout
 */
int buff_flush(char *buff, int *buff_i)
{
    if (*buff_i > 0)
        write(1, buff, *buff_i);

    *buff_i = 0;
    return 0;
}
