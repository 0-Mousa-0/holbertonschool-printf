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
int buf_add(char *buf, int *idx, char c);
int buf_add_str(char *buf, int *idx, const char *s);
int buf_flush(char *buf, int *idx);
int print_signed(char *buf, int *idx, long n);
int print_unsigned(char *buf, int *idx, unsigned int n);
int print_base(char *buf, int *idx, unsigned int n, unsigned int base, const char *digits);

#endif /* MAIN_H */
