#include <unistd.h>
#include <stdarg.h>
#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _putchar - writes the char to stdout
 * @c: character to be printed
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - writes character c
 * @params: The name for va_list
 *
 * Return: 1 on success, -1 on error
 */
int print_char(va_list *params)
{
	char c = va_arg(*params, int);

	_putchar(c);
	return (1);
}

/**
 * length_i - prints recursively
 * @i: number to get the length
 * @len: number length
 * Return: length.
 */
int length_i(unsigned int i, int len)
{
	while (i / 10)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

/**
 * repeat_i - prints recursively
 * @i: number to be printed
 * Return: void
 */
void repeat_i(unsigned int i)
{
	if (i / 10)
	{
		repeat_i(i / 10);
	}
	_putchar(i % 10 + '0');
}
/**
 * print_int - writes the int i
 * @param: va_list
 *
 * Return: 1 on success
 */
int print_int(va_list *param)
{
	int i = 0, len = 0, negative = 0;
	unsigned int limit;

	i = va_arg(*param, int);
	if (i < 0)
	{
		_putchar('-');
		limit = -i;
		negative = 1;
	}
	else
		limit = i;
	len += length_i(limit, len);
	repeat_i(limit);
	len = len + negative + 1;
	return (len);
}

/**
 * print_string - writes the string
 * @params: The name for va_list
 * Return: string Length.
 */
int print_string(va_list *params)
{
	int length = 0;
	char *str = va_arg(*params, char *);

	if (str == NULL)
		str = "(null)";
	while (str[length] != '\0')
	{
		_putchar(str[length]);
		length++;
	}

	return (length);
}
