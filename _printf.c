#include "main.h"

int print_char(char *buf, int *idx, char c)
{
    return buf_add(buf, idx, c);
}

int print_string(char *buf, int *idx, char *s)
{
    int count = 0;

    if (!s)
        s = "(null)";

    while (*s)
    {
        if (buf_add(buf, idx, *s++) == -1)
            return -1;
        count++;
    }
    return count;
}

int print_int(char *buf, int *idx, int n)
{
    unsigned int num;
    int count = 0;

    if (n < 0)
    {
        if (buf_add(buf, idx, '-') == -1)
            return -1;
        count++;
        num = -n;
    }
    else
        num = n;

    if (num / 10)
        count += print_int(buf, idx, num / 10);

    if (buf_add(buf, idx, (num % 10) + '0') == -1)
        return -1;

    return count + 1;
}

int _printf(const char *format, ...)
{
    va_list ap;
    char buffer[BUF_SIZE];
    int idx = 0, count = 0;

    va_start(ap, format);

    while (*format)
    {
        if (*format != '%')
        {
            if (buf_add(buffer, &idx, *format++) == -1)
                return -1;
            count++;
        }
        else
        {
            format++;
            if (*format == 'c')
                count += print_char(buffer, &idx, va_arg(ap, int));
            else if (*format == 's')
                count += print_string(buffer, &idx, va_arg(ap, char *));
            else if (*format == 'd' || *format == 'i')
                count += print_int(buffer, &idx, va_arg(ap, int));
            else if (*format == '%')
                count += buf_add(buffer, &idx, '%');
            else
                count += buf_add(buffer, &idx, *format);

            format++;
        }
    }

    buf_flush(buffer, &idx);
    va_end(ap);

    return count;
}
