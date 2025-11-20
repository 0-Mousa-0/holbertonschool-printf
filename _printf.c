#include "main.h"

/**
 * print_char - prints a char
 */
int print_char(va_list ap, char *buff, int *buff_i)
{
    char c = va_arg(ap, int);
    return buff_push(c, buff, buff_i);
}

/**
 * print_string - prints a string
 */
int print_string(va_list ap, char *buff, int *buff_i)
{
    char *s = va_arg(ap, char *);
    int count = 0;

    if (!s)
        s = "(null)";

    while (*s)
        count += buff_push(*s++, buff, buff_i);

    return count;
}

/**
 * print_percent - prints %
 */
int print_percent(char *buff, int *buff_i)
{
    return buff_push('%', buff, buff_i);
}

/**
 * print_int - prints integer
 */
int print_int(va_list ap, char *buff, int *buff_i)
{
    long n = va_arg(ap, int);
    int count = 0;

    if (n < 0)
    {
        count += buff_push('-', buff, buff_i);
        n = -n;
    }

    if (n / 10)
        count += print_int_helper(n / 10, buff, buff_i);

    count += buff_push((n % 10) + '0', buff, buff_i);
    return count;
}

/* helper for recursion */
int print_int_helper(long n, char *buff, int *buff_i)
{
    int count = 0;

    if (n / 10)
        count += print_int_helper(n / 10, buff, buff_i);

    count += buff_push((n % 10) + '0', buff, buff_i);

    return count;
}

/**
 * _printf - custom printf
 */
int _printf(const char *format, ...)
{
    va_list ap;
    char buff[1024];
    int buff_i = 0, count = 0;
    int i = 0;

    if (!format)
        return -1;

    va_start(ap, format);

    while (format[i])
    {
        if (format[i] != '%')
        {
            count += buff_push(format[i], buff, &buff_i);
            i++;
            continue;
        }

        i++;
        if (!format[i])
            break;

        switch (format[i])
        {
            case 'c': count += print_char(ap, buff, &buff_i); break;
            case 's': count += print_string(ap, buff, &buff_i); break;
            case '%': count += print_percent(buff, &buff_i); break;
            case 'd':
            case 'i': count += print_int(ap, buff, &buff_i); break;
            default:
                count += buff_push('%', buff, &buff_i);
                count += buff_push(format[i], buff, &buff_i);
        }
        i++;
    }

    buff_flush(buff, &buff_i);
    va_end(ap);
    return count;
}
