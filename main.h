#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

/* Core _printf function */
int _printf(const char *format, ...);

/* Helper functions */
int _putchar(char c);
int print_string(char *str);
int print_number(int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex_lower(unsigned int n);
int print_hex_upper(unsigned int n);
int print_pointer(void *ptr);

/* Buffer functions */
void buff_push(char *buff, int *buff_i, char c);
void buff_flush(char *buff, int *buff_i);

#endif /* MAIN_H */

