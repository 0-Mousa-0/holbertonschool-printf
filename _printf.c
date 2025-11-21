#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;

            switch (*format)
            {
                case 'c':
                    count += print_char(args);
                    break;
                case 's':
                    count += print_string(args);
                    break;
                case '%':
                    count += print_percent(args);
                    break;
                case 'd':
                case 'i':
                    count += print_int(args);
                    break;
                case 'p':
                    count += print_pointer(args);
                    break;
                default:
                    count += write(1, "%", 1);
                    count += write(1, format, 1);
                    break;
            }
        }
        else
        {
            count += write(1, format, 1);
        }
        format++;
    }

    va_end(args);
    return (count);
}
