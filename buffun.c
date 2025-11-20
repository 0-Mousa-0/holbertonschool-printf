#include "main.h"
/* Flush buffer */
void buf_flush(void)
{
    if (*idx > 0)
    {
     write(1, buf, *idx);
        *idx = 0;
    }
    return 1;
}
/* Add character to buffer */
int buf_add(char *buf, int *idx, char c)
{
    if (*idx >= BUF_SIZE)
       buf_flush();
       buf[idx++] = c;
       return 1;
}

