#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    /* ... your existing variable declarations ... */
    
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            /* ... your existing format parsing ... */
            
            switch (*format)
            {
                /* ... your existing cases ... */
                case 'c':
                    count += print_char(ap, buff, &buff_i);
                    break;
                case 's':
                    count += print_string(ap, buff, &buff_i);
                    break;
                case '%':
                    count += print_percent(buff, &buff_i);
                    break;
                case 'd':
                case 'i':
                    count += print_int(ap, buff, &buff_i);
                    break;
                case 'p':
                    count += print_pointer(ap, buff, &buff_i);
                    break;
                /* ... your other cases ... */
            }
        }
        /* ... rest of your existing code ... */
    }
    /* ... your existing cleanup code ... */
}
