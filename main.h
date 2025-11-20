#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

#define BUF_SIZE 1024

int _printf(const char *format, ...);

/* Buffer functions */
int buf_add(char *buf, int *idx, char c);
int buf_flush(char *buf, int *idx);

/* Print functions with buffer */
int print_char(char *buf, int *idx, char c);
int print_string(char *buf, int *idx, char *s);
int print_number(char *buf, int *idx, int n);
int print_binary(char *buf, int *idx, unsigned int n);
int print_pointer(char *buf, int *idx, void *ptr);
int print_custom_string(char *buf, int *idx, char *str);

#endif
