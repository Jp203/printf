#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "holberton.h"
/**
 * _printf - prints format needed
 * @format: The given format
 * Return: 1, -1 on error
 */
int _printf(const char *format, ...)
{
	va_list parameters;
	specifiers_list type_count;
	int count = 0, flagset = 1, length = 0;

	if ((format == NULL) || (format[0] == '%' && !format[count]))
		return (-1);
	va_start(parameters, format);
	while (format[count] != '\0')
	{
		if (format[count] != '%')
			if (flagset)
				length += _putchar(format[count]);
			else
			{
				type_count = specifier_list(format[i]);
				if (type_count.format != '*')
					length += type_count.func(&parameters);
				else
					length += _putchar('%') + _putchar(format[count]);
				flagset = 1;
			}
		else
			if (flagset)
				flagset = 0;
			else
			{
				length += _putchar(format[count]);
				flagset = 1;
			}
		count++;
	}
	va_end(parameters);
	return (length);
}
