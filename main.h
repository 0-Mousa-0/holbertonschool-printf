#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* main printf */
int _printf(const char *format, ...);

/* buffer functions */
int buff_push(char c, char *buff, int *buff_i);
int buff_flush(char *buff, int *buff_i);

/* specifier handlers */
int print_char(va_list ap, char *buff, int *buff_i);
int print_string(va_list ap, char *buff, int *buff_i);
int print_percent(char *buff, int *buff_i);
int print_int(va_list ap, char *buff, int *buff_i);
int print_binary(unsigned int n, char *buff, int *buff_i);


int print_int_helper(long n, char *buff, int *buff_i);


int print_S(va_list args);
#endif
