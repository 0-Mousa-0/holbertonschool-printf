#ifndef MAIN_H
#define MAIN_H
#define BUF_SIZE 1024

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

/* Buffer helpers */
int buf_add(char *buf, int *idx, char c);
int buf_flush(char *buf, int *idx);

/* Printers */
int print_string(char *buf, int *idx, char *s);
int print_signed(char *buf, int *idx, long n);
int print_unsigned(char *buf, int *idx, unsigned int n);
int print_base(char *buf, int *idx, unsigned int n, unsigned int base, const char *digits);

#endif
