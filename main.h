#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* Main printf function */
int _printf(const char *format, ...);

/* Helper functions */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_pointer(va_list args);

/* Utility functions */
int _putchar(char c);
int print_number(int n);
unsigned int print_unsigned(unsigned int n);
int print_hex(unsigned long n, int uppercase);

#endif /* MAIN_H */
