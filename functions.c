#include "main.h"

/**
 * _putchar - prints a single character
 * @c: the character to print
 *
 * Return: number of bytes written (1), or -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @str: string to print
 *
 * Return: number of characters printed
 */
int print_string(char *str)
{
	int c = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		c += _putchar(*str);
		str++;
	}
	return (c);
}

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	int c = 0;
	unsigned int num;

	if (n < 0)
	{
		c += _putchar('-');
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		c += print_number(num / 10);
	c += _putchar(num % 10 + '0');

	return (c);
}

/**
 * print_binary - prints an unsigned int in binary
 * @n: number to print in binary
 *
 * Return: number of digits printed
 */
int print_binary(unsigned int n)
{
	int c = 0;

	if (n > 1)
		c += print_binary(n / 2);

	c += _putchar((n % 2) + '0');
	return (c);
}

/**
 * print_pointer - prints a pointer address in hexadecimal
 * @ptr: pointer to print
 *
 * Return: number of characters printed
 */
int print_pointer(void *ptr)
{
	unsigned long address = (unsigned long)ptr;
	int count = 0;
	int digit, i = 0;
	char buffer[20];

	if (ptr == NULL)
		return (print_string("(nil)"));

	/* Convert to hexadecimal */
	if (address == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (address > 0)
		{
			digit = address % 16;
			buffer[i++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
			address /= 16;
		}
	}

	/* Print "0x" prefix */
	count += _putchar('0');
	count += _putchar('x');

	/* Print digits in reverse order */
	while (i > 0)
		count += _putchar(buffer[--i]);

	return (count);
}
