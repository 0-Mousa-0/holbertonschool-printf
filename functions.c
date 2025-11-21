#include "main.h"

/**
 * print_char - prints a character
 * @args: arguments list
 * Return: number of characters printed
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @args: arguments list
 * Return: number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL)
        str = "(null)";

    while (*str)
    {
        count += write(1, str, 1);
        str++;
    }
    return (count);
}

/**
 * print_percent - prints a percent sign
 * @args: arguments list
 * Return: number of characters printed
 */
int print_percent(va_list args)
{
    (void)args;
    return (write(1, "%", 1));
}

/**
 * print_number - prints an integer
 * @n: integer to print
 * Return: number of characters printed
 */
int print_number(int n)
{
    int count = 0;
    unsigned int num;

    if (n < 0)
    {
        count += _putchar('-');
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num / 10)
        count += print_number(num / 10);

    count += _putchar((num % 10) + '0');
    return (count);
}

/**
 * print_int - prints integer
 * @args: arguments list
 * Return: number of characters printed
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    return (print_number(n));
}

/**
 * print_hex - prints hexadecimal number
 * @n: number to print
 * @uppercase: 1 for uppercase, 0 for lowercase
 * Return: number of characters printed
 */
int print_hex(unsigned long n, int uppercase)
{
    int count = 0;
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n / 16)
        count += print_hex(n / 16, uppercase);

    count += _putchar(digits[n % 16]);
    return (count);
}

/**
 * print_pointer - prints a pointer address
 * @args: arguments list
 * Return: number of characters printed
 */
int print_pointer(va_list args)
{
    void *ptr = va_arg(args, void *);
    unsigned long address = (unsigned long)ptr;
    int count = 0;

    if (ptr == NULL)
    {
        return (write(1, "(nil)", 5));
    }

    /* Print "0x" prefix */
    count += write(1, "0x", 2);
    
    /* Print hexadecimal address */
    count += print_hex(address, 0);

    return (count);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1, on error -1
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}
