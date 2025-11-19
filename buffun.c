#include "main.h"

/* append a single char to buffer, flush if full */
int buf_add(char *buf, int *idx, char c)
{
    if (*idx >= 1024)
    {
        if (write(1, buf, *idx) == -1)
            return -1;
        *idx = 0;
    }
    buf[(*idx)++] = c;
    return 1;
}

/* append a string */
int buf_add_str(char *buf, int *idx, const char *s)
{
    int count = 0;
    if (!s)
        s = "(null)";

    while (*s)
    {
        if (buf_add(buf, idx, *s) == -1)
            return -1;
        s++;
        count++;
    }
    return count;
}

/* flush the content of buffer */
int buf_flush(char *buf, int *idx)
{
    int w;

    if (*idx > 0)
    {
        w = write(1, buf, *idx);
        if (w == -1)
            return -1;
        *idx = 0;
        return w;
    }
    return 0;
}

/* signed integer */
int print_signed(char *buf, int *idx, long n)
{
    int count = 0;
    unsigned long v;

    if (n < 0)
    {
        if (buf_add(buf, idx, '-') == -1)
            return -1;
        count++;
        v = -n;
    }
    else
        v = n;

    if (v / 10)
    {
        int r = print_signed(buf, idx, v / 10);
        if (r == -1) return -1;
        count += r;
    }
    if (buf_add(buf, idx, '0' + (v % 10)) == -1)
        return -1;

    return count + 1;
}

/* unsigned */
int print_unsigned(char *buf, int *idx, unsigned int n)
{
    int count = 0;

    if (n / 10)
    {
        int r = print_unsigned(buf, idx, n / 10);
        if (r == -1) return -1;
        count += r;
    }

    if (buf_add(buf, idx, '0' + (n % 10)) == -1)
        return -1;

    return count + 1;
}

/* base converter */
int print_base(char *buf, int *idx, unsigned int n, unsigned int base, const char *digits)
{
    int count = 0;

    if (n / base)
    {
        int r = print_base(buf, idx, n / base, base, digits);
        if (r == -1) return -1;
        count += r;
    }

    if (buf_add(buf, idx, digits[n % base]) == -1)
        return -1;

    return count + 1;
}
