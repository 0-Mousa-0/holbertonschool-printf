#include "main.h"

/* Add character to buffer */
int buf_add(char *buf, int *idx, char c)
{
	if (*idx >= BUF_SIZE)
	{
		if (write(1, buf, *idx) == -1)
			return (-1);
		*idx = 0;
	}
	buf[(*idx)++] = c;
	return (1);
}

/* Flush buffer */
int buf_flush(char *buf, int *idx)
{
	if (*idx > 0)
	{
		if (write(1, buf, *idx) == -1)
			return (-1);
		*idx = 0;
	}
	return (1);
}

/* Print character */
int print_char(char *buf, int *idx, char c)
{
	return (buf_add(buf, idx, c));
}

/* Print string */
int print_string(char *buf, int *idx, char *s)
{
	int count = 0;

	if (!s)
		s = "(null)";

	while (*s)
	{
		if (buf_add(buf, idx, *s++) == -1)
			return (-1);
		count++;
	}
	return (count);
}

/* Print number (integer) */
int print_number(char *buf, int *idx, int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		if (buf_add(buf, idx, '-') == -1)
			return (-1);
		count++;
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		count += print_number(buf, idx, num / 10);

	if (buf_add(buf, idx, (num % 10) + '0') == -1)
		return (-1);

	return (count + 1);
}

/* Print binary */
int print_binary(char *buf, int *idx, unsigned int n)
{
	int count = 0;

	if (n > 1)
		count += print_binary(buf, idx, n / 2);

	if (buf_add(buf, idx, (n % 2) + '0') == -1)
		return (-1);

	return (count + 1);
}

/* Print pointer */
int print_pointer(char *buf, int *idx, void *ptr)
{
	unsigned long address = (unsigned long)ptr;
	int count = 0;
	int digit, i = 0;
	char temp[20];

	if (ptr == NULL)
		return (print_string(buf, idx, "(null)"));

	/* Convert to hexadecimal */
	if (address == 0)
	{
		temp[i++] = '0';
	}
	else
	{
		while (address > 0)
		{
			digit = address % 16;
			temp[i++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
			address /= 16;
		}
	}

	/* Add "0x" prefix */
	count += buf_add(buf, idx, '0');
	count += buf_add(buf, idx, 'x');

	/* Add digits in reverse order */
	while (i > 0)
		count += buf_add(buf, idx, temp[--i]);

	return (count);
}

/* Print custom string with non-printable characters */
int print_custom_string(char *buf, int *idx, char *str)
{
	int count = 0;
	unsigned char current;

	if (str == NULL)
		return (print_string(buf, idx, "(null)"));

	while (*str)
	{
		current = (unsigned char)*str;
		
		/* Check if character is non-printable */
		if ((current > 0 && current < 32) || current >= 127)
		{
			count += buf_add(buf, idx, '\\');
			count += buf_add(buf, idx, 'x');
			count += buf_add(buf, idx, "0123456789ABCDEF"[current / 16]);
			count += buf_add(buf, idx, "0123456789ABCDEF"[current % 16]);
		}
		else
		{
			count += buf_add(buf, idx, current);
		}
		str++;
	}

	return (count);
}
