#include "main.h"

/**
 * print_S - prints a string with non-printable chars in \xHH format
 */
int print_S(va_list args)
{
    char *s = va_arg(args, char *);
    int count = 0;
    unsigned char c;
    char hex_map[] = "0123456789ABCDEF";

    if (!s)
        s = "(null)";

    while (*s)
    {
        c = (unsigned char)*s;

        if ((c > 0 && c < 32) || c >= 127)
        {
            /* always print exactly 2 hex digits */
            write(1, "\\x", 2);
            write(1, &hex_map[(c >> 4) & 0xF], 1);
            write(1, &hex_map[c & 0xF], 1);
            count += 4;
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
