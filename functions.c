#include "main.h"

/* Prints a single character */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/* Prints a string */
int print_string(char *str)
{
    int count = 0;

    if (!str)
        str = "(null)";
    while (*str)
    {
        count += _putchar(*str++);
    }
    return count;
}

/* Prints a signed integer */
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
        num = n;

    if (num / 10)
        count += print_number(num / 10);
    count += _putchar(num % 10 + '0');

    return count;
}

/* Prints unsigned integer */
int print_unsigned(unsigned int n)
{
    int count = 0;

    if (n / 10)
        count += print_unsigned(n / 10);
    count += _putchar(n % 10 + '0');

    return count;
}

/* Prints hexadecimal lowercase */
int print_hex_lower(unsigned int n)
{
    char hex[] = "0123456789abcdef";
    int count = 0;

    if (n / 16)
        count += print_hex_lower(n / 16);
    count += _putchar(hex[n % 16]);
    return count;
}

/* Prints hexadecimal uppercase */
int print_hex_upper(unsigned int n)
{
    char hex[] = "0123456789ABCDEF";
    int count = 0;

    if (n / 16)
        count += print_hex_upper(n / 16);
    count += _putchar(hex[n % 16]);
    return count;
}

/* Prints pointer address */
int print_pointer(void *ptr)
{
    int count = 0;
    unsigned long addr;

    if (!ptr)
        return print_string("(nil)");

    addr = (unsigned long)ptr;
    count += print_string("0x");

    if (addr / 16)
        count += print_pointer((void *)(addr / 16));
    count += _putchar("0123456789abcdef"[addr % 16]);

    return count;
}

