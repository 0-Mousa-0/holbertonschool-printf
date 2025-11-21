#include "main.h"

/**
 * print_hex - prints hexadecimal number using buffer
 * @n: number to print
 * @buff: output buffer
 * @buff_i: buffer index pointer
 * @uppercase: 1 for uppercase, 0 for lowercase
 * Return: number of characters printed
 */
int print_hex(unsigned long n, char *buff, int *buff_i, int uppercase)
{
    int count = 0;
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n / 16)
        count += print_hex(n / 16, buff, buff_i, uppercase);

    count += buff_push(digits[n % 16], buff, buff_i);
    return (count);
}

/**
 * print_pointer - prints a pointer address using buffer
 * @ap: arguments list
 * @buff: output buffer
 * @buff_i: buffer index pointer
 * Return: number of characters printed
 */
int print_pointer(va_list ap, char *buff, int *buff_i)
{
    void *ptr = va_arg(ap, void *);
    unsigned long address = (unsigned long)ptr;
    int count = 0;

    if (ptr == NULL)
    {
        /* Print "(nil)" for NULL pointer */
        count += buff_push('(', buff, buff_i);
        count += buff_push('n', buff, buff_i);
        count += buff_push('i', buff, buff_i);
        count += buff_push('l', buff, buff_i);
        count += buff_push(')', buff, buff_i);
        return (count);
    }

    /* Print "0x" prefix */
    count += buff_push('0', buff, buff_i);
    count += buff_push('x', buff, buff_i);
    
    /* Print hexadecimal address */
    if (address == 0)
    {
        count += buff_push('0', buff, buff_i);
    }
    else
    {
        count += print_hex(address, buff, buff_i, 0);
    }

    return (count);
}
