#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int _printf(const char *format, ...);
int print_unsigned(unsigned int num);
int print_octal(unsigned int num);
int print_hex(int num, int is_upper);

#endif
