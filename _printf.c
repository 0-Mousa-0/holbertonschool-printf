#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	while (*format) /*format != NULL*/
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'u')
				i += print_unsigned(va_arg(args, unsigned int));
			else if (*format == 'o')
				i += print_octal(va_arg(args, unsigned int));
			else if (*format == 'x')
                                i += print_hex_l(va_arg(args, unsigned int));
			else if (*format == 'X')
                                i += print_hex_u(va_arg(args, unsigned int));
			else
			{
				i += _putchar('%');
				i += _putchar(*format);
			}
		}
		else
			i += _putchar(*format);
		format++;
	}

	va_end(args);
	return (i);
}
