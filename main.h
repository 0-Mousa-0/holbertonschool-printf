#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUF_SIZE 1024

int _printf(const char *format, ...);

int buf_add(char *buf, int *idx, char c);
int buf_flush(char *buf, int *idx);

int print_char(char *buf, int *idx, char c);
int print_string(char *buf, int *idx, char *s);
int print_int(char *buf, int *idx, int n);
int print_binary(char *buf, int *idx, unsigned int n);

#endif
