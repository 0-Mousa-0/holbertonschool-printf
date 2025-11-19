#include "main.h"

int _printf(const char *format, ...)
{
    char buf[1024];
    int idx = 0, count = 0;
    va_list args;

    if (!format)
        return -1;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            if (buf_add(buf, &idx, *format) == -1)
                return -1;
            count++;
            format++;
            continue;
        }

        format++; /* skip % */

        switch (*format)
        {
            case 'c':
                if (buf_add(buf, &idx, va_arg(args, int)) == -1)
                    return -1;
                count++;
                break;

            case 's':
                {
                    int r = print_string(buf, &idx, va_arg(args, char *));
                    if (r == -1) return -1;
                    count += r;
                }
                break;

            case 'd':
            case 'i':
                {
                    int r = print_signed(buf, &idx, va_arg(args, int));
                    if (r == -1) return -1;
                    count += r;
                }
                break;

            case 'u':
                {
                    int r = print_unsigned(buf, &idx, va_arg(args, unsigned int));
                    if (r == -1) return -1;
                    count += r;
                }
                break;

            case 'x':
                {
                    int r = print_base(buf, &idx, va_arg(args, unsigned int),
                                       16, "0123456789abcdef");
                    if (r == -1) return -1;
                    count += r;
                }
                break;

            case 'X':
                {
                    int r = print_base(buf, &idx, va_arg(args, unsigned int),
                                       16, "0123456789ABCDEF");
                    if (r == -1) return -1;
                    count += r;
                }
                break;

            case 'o':
                {
                    int r = print_base(buf, &idx, va_arg(args, unsigned int),
                                       8, "01234567");
                    if (r == -1) return -1;
                    count += r;
                }
                break;

            case 'b':
                {
                    int r = print_base(buf, &idx, va_arg(args, unsigned int),
                                       2, "01");
                    if (r == -1) return -1;
                    count += r;
                }
                break;

            case '%':
                if (buf_add(buf, &idx, '%') == -1)
                    return -1;
                count++;
                break;

            default:
                /* Unknown specifier: print '%X' literally */
                if (buf_add(buf, &idx, '%') == -1)
                    return -1;
                if (buf_add(buf, &idx, *format) == -1)
                    return -1;
                count += 2;
                break;
        }

        format++;
    }

    buf_flush(buf, &idx);
    va_end(args);
    return count;
}

