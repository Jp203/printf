#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>
/**
 * struct specifier - structure for each format specifier to be used
 * @format: specifier
 * @func: function for each format
 */
typedef struct specifier
{
	char format;
	int (*func)(va_list *);
} specifier_list;

int _putchar(char c);
/* Functions */
specifiers_list select_type(char s);
int _printf(const char *format, ...);
int print_char(va_list *);
int print_string(va_list *);
int print_int(va_list *);
int print_unsigned_int(va_list *);
int print_double(va_list *);
int print_octal(va_list *);
int print_hexa(va_list *);
int print_lower_hexa(va_list *);
int print_binary(va_list *);
int print_special(va_list *);
int print_rot13(va_list *params);
int print_reverse(va_list *);
#endif
