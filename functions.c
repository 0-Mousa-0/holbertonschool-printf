#include "main.h"

/**
 * print_S - custom specifier %S
 * prints string, non printable chars as \xHH (uppercase hex)
 */
int print_S(va_list args)
{
    char *s = va_arg(args, char *);
    int count = 0;
    char hex_map[] = "0123456789ABCDEF";
    unsigned char c;

    if (!s)
        s = "(null)";

    while (*s)
    {
        c = (unsigned char)*s;

        if ((c > 0 && c < 32) || c >= 127)
        {
            count += write(1, "\\x", 2);
            count += write(1, &hex_map[c / 16], 1);
            count += write(1, &hex_map[c % 16], 1);
        }
        else
        {
            write(1, &c, 1);
            count++;
        }
        s++;
    }

    return count;
}
