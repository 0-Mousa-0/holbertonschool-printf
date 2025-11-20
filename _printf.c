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

int print_int(char *buf, int *idx, long n)
{
    unsigned long v;
    int count = 0;

    if (n < 0)
    {
        if (buf_add(buf, idx, '-') == -1)
            return -1;
        count++;
        v = -n;
    }
    else
        v = n;

    if (v / 10)
    {
        int r = print_int(buf, idx, v / 10);
        if (r == -1) return -1;
        count += r;
    }

    if (buf_add(buf, idx, '0' + (v % 10)) == -1)
        return -1;

    return count + 1;
}

int print_base(char *buf, int *idx, unsigned int n, unsigned int base, const char *digits)
{
    int count = 0;

    if (n / base)
    {
        int r = print_base(buf, idx, n / base, base, digits);
        if (r == -1) return -1;
        count += r;
    }

    if (buf_add(buf, idx, digits[n % base]) == -1)
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

            else if (*format == 'b')
                count += print_base(buffer, &idx, va_arg(ap, unsigned int), 2, "01");

            else if (*format == '%')
                count += buf_add(buffer, &idx, '%');

            else
            {
                /* Unknown specifier → print % + specifier */
                count += buf_add(buffer, &idx, '%');
                count += buf_add(buffer, &idx, *format);
            }

            format++;
        }
    }

    buf_flush(buffer, &idx);
    va_end(ap);

    return count;
}
