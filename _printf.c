#include "main.h"

int _printf(const char *format, ...)
{
    char buf[1024];
    int idx = 0;
    int total = 0;

    va_list args;
    va_start(args, format);

    if (!format)
        return -1;

    while (*format)
    {
        if (*format != '%')
        {
            if (buf_add(buf, &idx, *format) == -1)
                return -1;
            total++;
            format++;
            continue;
        }

        format++;  /* skip % */

        switch (*format)
        {
            case 'c':
            {
                int ch = va_arg(args, int);
                if (buf_add(buf, &idx, (char)ch) == -1)
                    return -1;
                total++;
                break;
            }

            case 's':
            {
                int r = buf_add_str(buf, &idx, va_arg(args, char *));
                if (r == -1) return -1;
                total += r;
                break;
            }

            case '%':
            {
                if (buf_add(buf, &idx, '%') == -1)
                    return -1;
                total++;
                break;
            }

            case 'd':
            case 'i':
            {
                int r = print_signed(buf, &idx, va_arg(args, int));
                if (r == -1) return -1;
                total += r;
                break;
            }

            case 'u':
            {
                int r = print_unsigned(buf, &idx, va_arg(args, unsigned int));
                if (r == -1) return -1;
                total += r;
                break;
            }

            case 'o':
            {
                int r = print_base(buf, &idx, va_arg(args, unsigned int), 8, "01234567");
                if (r == -1) return -1;
                total += r;
                break;
            }

            case 'x':
            {
                int r = print_base(buf, &idx, va_arg(args, unsigned int), 16, "0123456789abcdef");
                if (r == -1) return -1;
                total += r;
                break;
            }

            case 'X':
            {
                int r = print_base(buf, &idx, va_arg(args, unsigned int), 16, "0123456789ABCDEF");
                if (r == -1) return -1;
                total += r;
                break;
            }

            case 'b':
            {
                int r = print_base(buf, &idx, va_arg(args, unsigned int), 2, "01");
                if (r == -1) return -1;
                total += r;
                break;
            }

            default:
                /* unknown specifier → print '%' and the char */
                buf_add(buf, &idx, '%');
                buf_add(buf, &idx, *format);
                total += 2;
                break;
        }
        format++;
    }

    if (buf_flush(buf, &idx) == -1)
        return -1;

    va_end(args);
    return total;
}
