#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
int print_string(char *str);
int print_number(int n);
int print_binary(unsigned int n);
int _printf(const char *format, ...);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex_l(unsigned int n);
int print_hex_u(unsigned int n);

#endif /* MAIN_H */
