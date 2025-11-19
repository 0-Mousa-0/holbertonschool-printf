#include "main.h"

/**
 * print_unsigned - prints an unsigned int in decimal
 * @n: number to print
 * Return: number of chars printed
 */

int print_unsigned(unsigned int n)
{
int c = 0;

if (n / 10)
c += print_unsigned(n / 10);

c += _putchar((n % 10) + '0');

return (c);
}
/**
 * print_octal - prints an unsigned int in octal
 * @n: number to print
 * Return: number of chars printed
 */
int print_octal(unsigned int n)
{
int c = 0;

if (n / 8)
c += print_octal(n / 8);

c += _putchar((n % 8) + '0');

return (c);
}
/**
 * print_hex_l - prints an unsigned int in lowercase hexadecimal
 * @n: number to print
 * Return: number of chars printed
 */

int print_hex_l(unsigned int n)
{
int c = 0;
char *x = "0123456789abcdef";

if (n / 16)
c += print_hex_l(n / 16);

c += _putchar(x[n % 16]);
return (c);
}

/**
 * print_hex_u - prints an unsigned int in uppercase hexadecimal
 * @n: number to print
 * Return: number of chars printed
 */


int print_hex_u(unsigned int n)
{
int c = 0;
char *x = "0123456789ABCDEF";

if (n / 16)
c += print_hex_u(n / 16);

c += _putchar(x[n % 16]);
return (c);
}


