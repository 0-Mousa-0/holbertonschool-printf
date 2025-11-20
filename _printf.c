#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char buffer[BUF_SIZE];
	int idx = 0, count = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(ap, format);

	while (*format)
	{
		if (*format != '%')
		{
			if (buf_add(buffer, &idx, *format) == -1)
				return (-1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
				
			if (*format == 'c')
				count += print_char(buffer, &idx, va_arg(ap, int));
			else if (*format == 's')
				count += print_string(buffer, &idx, va_arg(ap, char *));
			else if (*format == 'd' || *format == 'i')
				count += print_number(buffer, &idx, va_arg(ap, int));
			else if (*format == 'b')
				count += print_binary(buffer, &idx, va_arg(ap, unsigned int));
			else if (*format == 'p')
				count += print_pointer(buffer, &idx, va_arg(ap, void *));
			else if (*format == 'S')
				count += print_custom_string(buffer, &idx, va_arg(ap, char *));
			else if (*format == '%')
				count += buf_add(buffer, &idx, '%');
			else
			{
				count += buf_add(buffer, &idx, '%');
				count += buf_add(buffer, &idx, *format);
			}
		}
		format++;
	}

	buf_flush(buffer, &idx);
	va_end(ap);

	return (count);
}
