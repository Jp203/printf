#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"
/**
 * select_specifier - Selects a  format
 * @format: the format to be printed
 * Return: parameters w/ needed specifier
 */
specifier_list select_type(char format)
{
	int count, formats = 16;
	specifier_list types[] = {
		{'c', print_char},
		{'s', print_string},
		{'i', print_int},
		{'u', print_unsigned_int},
		{'d', print_double},
		{'o', print_octal},
		{'x', print_lower_hexa},
		{'X', print_hexa},
		{'b', print_binary},
		{'R', print_rot13},
		{'S', print_string},
		{'p', print_lower_hexa},
		{'r', print_reverse},
		{'l', print_unsigned_int},
		{'h', print_unsigned_int},
		{'*', print_special}
	};

	for (count = 0; count < formats; count++)
		if (types[count].format == format)
			return (types[count]);
	return (types[count - 1]);
}
