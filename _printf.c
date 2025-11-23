#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;

    if (!format)
        return -1;

    va_start(args, format);
    ptr = format;

    while (*ptr)
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == 'c')
                count += _putchar(va_arg(args, int));
            else if (*ptr == 's')
                count += print_string(va_arg(args, char *));
            else if (*ptr == 'd' || *ptr == 'i')
                count += print_number(va_arg(args, int));
            else if (*ptr == 'u')
                count += print_unsigned(va_arg(args, unsigned int));
            else if (*ptr == 'o')
                count += print_octal(va_arg(args, unsigned int));
            else if (*ptr == 'x')
                count += print_hex_lower(va_arg(args, unsigned int));
            else if (*ptr == 'X')
                count += print_hex_upper(va_arg(args, unsigned int));
            else if (*ptr == 'p')
                count += print_pointer(va_arg(args, void *));
            else if (*ptr == '%')
                count += _putchar('%');
            else if (*ptr == 'S')
                count += print_string_S(va_arg(args, char *));
            else
                count += _putchar('%'), count += _putchar(*ptr);
        }
        else
            count += _putchar(*ptr);

        ptr++;
    }

    va_end(args);
    return count;
}

