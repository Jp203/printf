#include <stdarg.h>
#include "holberton.h"
/**
 * print_number - recursively print numbers
 * @value: The number to be printed
 * @length: The amount of digits to be printed
 * Return: length
 */
int print_number(unsigned int value, int length)
{
	if (value / 10)
		length = print_number(value / 10, length + 1);
	_putchar(value % 10 + '0');
	return (length);
}

/**
 * print_int_unsigned - prints unsigned
 * @params: va_list
 *
 * Return: number length or -1 if returned.
 */
int print_unsigned_int(va_list *params)
{
	int count = 0, less = 0;
	unsigned int value = va_arg(*params, unsigned int);

	length = print_number(value, count) + less + 1;
	return (count);
}

/**
 * print_base2 - print numbers in binary recursively
 * @value: number to be printed
 * @length: amount of digits to be printed
 *
 * Return: length.
 */
int print_base2(unsigned int value, int length)
{
	if (value / 2)
		length = print_base2(value / 2, length + 1);
	_putchar(value % 2 + '0');
	return (length);
}
/**
 * print_binary - print binary
 * @params: va_list parameter
 *
 * Return: result in binary
 */
int print_binary(va_list *params)
{
	int result = 0;
	unsigned int b = va_arg(*params, unsigned int);

	result = print_base2(b, result) + 1;
	return (result);
}

/**
 * print_base8 - prints number in base 8 recursively
 * @value: The number to be printed
 * @length: The amount of digits to be printed.
 * Return: length.
 */
int print_base8(unsigned int value, int length)
{
	if (value / 8)
		length = print_base8(value / 8, length + 1);
	_putchar(value % 8 + '0');
	return (length);
}

/**
 * print_octal - convert decimal to octal
 * @params: va_list
 * Return: result or -1 is returned
 */
int print_octal(va_list *params)
{
	int result = 0;
	unsigned int value = va_arg(*params, unsigned int);

	result = print_base8(value, result) + 1;
	return (result);
}

/**
 * print_rot13 - converts to rot13
 * @params: va_list
 *  Return: String Length.
 */
int print_rot13(va_list *params)
{
	int result = 0, count = 0, j;
	char out[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char in[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str = va_arg(*params, char *);

	while (str[result])
		result++;
	if (str == NULL)
	{
		str = "(null)";
	}
	for (count = 0; str[count] != '\0' ; count++)
	{
		j = 0;
		while (str[j])
		{
			if (str[count] == out[j])
			{
				_putchar(in[j]);
				break;
			}
			j++;
		}
	}

	return (result);
}
