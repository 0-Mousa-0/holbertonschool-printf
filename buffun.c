#include "main.h"

/**
 * buff_push - push character to buffer
 * @c: character to push
 * @buff: buffer
 * @buff_i: buffer index pointer
 * Return: 1 on success
 */
int buff_push(char c, char *buff, int *buff_i)
{
    if (*buff_i >= 1024)
        buff_flush(buff, buff_i);
    
    buff[(*buff_i)++] = c;
    return (1);
}

/**
 * buff_flush - flush buffer to stdout
 * @buff: buffer
 * @buff_i: buffer index pointer
 */
void buff_flush(char *buff, int *buff_i)
{
    if (*buff_i > 0)
    {
        write(1, buff, *buff_i);
        *buff_i = 0;
    }
}
