# Printf Project (Holberton School-SAU 1025)
---
## 📌 Table of Contents
- [Overview](#^=^s^x Overview)
- [How it's work](#��� How Formatted Output Works in `_printf`)
- [Project Requirements](#^=^s^k Project Requirements)
                              
                            - [_printf function](#Structure Of _prinf)
  - [%c](#c---character)
  - [%s](#s---string)
  - [%%](#---percent-sign)
  - [%d, %i](#d---decimal && i---integer)
  - [%b](#b---binary)
  - [%u](#u---unsigned-integer)
  - [%o](#o---octal)
  - [%x](#x---hex-lowercase)
  - [%X](#X---hex-uppercase)
  - [%S](#S---non-printable-string)

- [Authors](#Authors)

---

## 📘 Overview
This project is a custom implementation of the standard C library function `printf`.  
The goal is to understand variadic functions, formatted output, buffer optimization, and custom specifiers.

The implementation handles a variety of format specifiers, including the required basic conversions and several extended custom ones.

---

## 🧩 How Formatted Output Works in `_printf`

The `_printf` function is a simplified custom implementation of the standard C library `printf`.  
It reads a **format string** character by character and prints each character directly to the output, unless it encounters a **conversion directive** — a special sequence that starts with the `%` symbol.

A conversion directive tells `_printf` how to interpret the next argument passed through `va_list`, and how to format it before printing.


In this project, we implement a focused set of commonly-used specifiers that handle characters, strings, numbers, and custom formats.  
Every specifier triggers a specific function responsible for formatting and printing the corresponding data type.

### 🔍 Supported Format Specifiers

| Specifier | Description |
|----------|-------------|
| `%c` | Prints a single character. |
| `%s` | Prints a null-terminated string. |
| `%%` | Prints the percent sign itself. |
| `%d`, `%i` | Prints a signed decimal integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%o` | Prints an unsigned number in octal (base 8). |
| `%x` | Prints an unsigned number in lowercase hexadecimal (base 16). |
| `%X` | Prints an unsigned number in uppercase hexadecimal. |
| `%b` | Prints an unsigned integer in binary representation. |
| `%S` | Prints a string, but converts non-printable ASCII characters into `\xHH` format (uppercase hex). |

### 🛠 How `_printf` Handles Specifiers

When `_printf` encounters a `%`, it immediately checks the next character to determine which handler to call.  
For example:

- `%d` → calls `print_int()`
- `%x` → calls `print_hex_lower()`
- `%b` → calls `print_binary()`
- `%S` → calls `print_string_S()`

Each handler function:
1. Receives the corresponding argument from `va_arg`
2. Converts it based on the required format (binary, hex, decimal…)
3. Prints it using `write(1, ...)`
4. Returns the number of characters printed

This modular design keeps `_printf` simple, readable, and easy to extend with additional specifiers in the future.



---

## 📋 Project Requirements
- Function prints formatted output to **stdout**
- Prototype:  
  ```c
  int _printf(const char *format, ...);

---

## Structure Of _prinf

```c
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: format string
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (!format)
        return -1;

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;

            /*  
             *  Case switch:
             */
        }
        else
        {
            count += write(1, &format[i], 1);
        }
        i++;
    }

    va_end(args);
    return count;
}

---

## c---character

```c
int print_char(char c)
{
    return write(1, &c, 1);
}

/* CASE FOR _printf */
case 'c':
    count += print_char(va_arg(args, int));
    break;

---

## s---string

```c
int print_string(char *s)
{
    int count = 0;

    if (!s)
        s = "(null)";

    while (*s)
        count += write(1, s++, 1);

    return count;
}

/* CASE FOR _printf */
case 's':
    count += print_string(va_arg(args, char *));
    break;

---

## ---percent-sign

```c
int print_percent(void)
{
    return write(1, "%", 1);
}

/* CASE FOR _printf */
case '%':
    count += print_percent();
    break;

---

## d---decimal && i---integer

```c
int print_int(int n)
{
    int count = 0;
    unsigned int num;

    if (n < 0)
    {
        count += write(1, "-", 1);
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num / 10)
        count += print_int(num / 10);

    count += write(1, (char[]){(num % 10) + '0'}, 1);

    return count;
}

/* CASE FOR _printf */
case 'd':
    count += print_int(va_arg(args, int));
    break;
case 'i':
    count += print_int(va_arg(args, int));
    break;

---

## b---binary

```c 
int print_binary(unsigned int n)
{
    int count = 0;

    if (n / 2)
        count += print_binary(n / 2);

    count += write(1, (char[]){'0' + (n % 2)}, 1);

    return count;
}

/* CASE FOR _printf */
case 'b':
    count += print_binary(va_arg(args, unsigned int));
    break;

---

## u---unsigned-integer

```c
int print_unsigned(unsigned int n)
{
    int count = 0;

    if (n / 10)
        count += print_unsigned(n / 10);

    count += write(1, (char[]){(n % 10) + '0'}, 1);

    return count;
}

/* CASE FOR _printf */
case 'u':
    count += print_unsigned(va_arg(args, unsigned int));
    break;

---

## o---octal

```c
int print_octal(unsigned int n)
{
    int count = 0;

    if (n / 8)
        count += print_octal(n / 8);

    count += write(1, (char[]){'0' + (n % 8)}, 1);

    return count;
}

/* CASE FOR _printf */
case 'o':
    count += print_octal(va_arg(args, unsigned int));
    break;

---

## x---hex-lowercase

```c
int print_hex_lower(unsigned int n)
{
    char *digits = "0123456789abcdef";
    int count = 0;

    if (n / 16)
        count += print_hex_lower(n / 16);

    count += write(1, &digits[n % 16], 1);

    return count;
}

/* CASE FOR _printf */
case 'x':
    count += print_hex_lower(va_arg(args, unsigned int));
    break;

---

## X---hex-uppercase

```c
int print_hex_upper(unsigned int n)
{
    char *digits = "0123456789ABCDEF";
    int count = 0;

    if (n / 16)
        count += print_hex_upper(n / 16);

    count += write(1, &digits[n % 16], 1);

    return count;
}

/* CASE FOR _printf */
case 'X':
    count += print_hex_upper(va_arg(args, unsigned int));
    break;

---

## S---non-printable-string

```c
int print_string_S(char *s)
{
    int count = 0;
    char hex[3];

    if (!s)
        s = "(null)";

    while (*s)
    {
        if (*s < 32 || *s >= 127)
        {
            count += write(1, "\\x", 2);

            sprintf(hex, "%02X", (unsigned char)*s);
            count += write(1, hex, 2);
        }
        else
        {
            count += write(1, s, 1);
        }
        s++;
    }

    return count;
}

/* CASE FOR _printf */
case 'S':
    count += print_string_S(va_arg(args, char *));
    break;

---

## Authors


Raghad Almalki / Mousa Alqarni 
SAU 1025 members 🔥.
