#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* Main printf function */
int _printf(const char *format, ...);

/* Buffer functions */
int buff_push(char c, char *buff, int *buff_i);
void buff_flush(char *buff, int *buff_i);

/* Helper functions */
int print_char(va_list ap, char *buff, int *buff_i);
int print_string(va_list ap, char *buff, int *buff_i);
int print_percent(char *buff, int *buff_i);
int print_int(va_list ap, char *buff, int *buff_i);
int print_pointer(va_list ap, char *buff, int *buff_i);

/* Utility functions */
int print_hex(unsigned long n, char *buff, int *buff_i, int uppercase);

#endif /* MAIN_H */
