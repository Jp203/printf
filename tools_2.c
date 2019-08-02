#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "holberton.h"


/**
 * length_d - prints recursively
 * @i: number to get the length
 * @len: number length
 * Return: length
 */
int length_d(unsigned int i, int len)
{
	while (i / 10)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

/**
 * repeat_d - prints recursively
 * @i: number to be printed
 * Return: void
 */
void repeat_d(unsigned int i)
{
	if (i / 10)
	{
		repeat_d(i / 10);
	}
	_putchar(i % 10 + '0');
}
/**
 * print_double - writes the double i
 * @param: va_list
 * Return: 1
 */
int print_double(va_list *param)
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
	len += length_d(limit, len);
	repeat_d(limit);
	len = len + negative + 1;
	return (len);
}


/**
 * _print_rev_recursion - Prints a string in reverse, followed by a new line
 * @s: the string to be printed
 * @length: string length to be calculated
 * Return: string length
 */
int _print_rev_recursion(char *s, int length)
{
	if (s[0] != '\0')
	{
		length = _print_rev_recursion(s + 1, length + 1);
		_putchar(s[0]);
	}
	return (length);
}
/**
 * print_reverse - writes the string in reverse
 * @params:  va_list
 * Return: string Length.
 */
int print_reverse(va_list *params)
{
	int length = 0;
	char *str = va_arg(*params, char *);

	if (str == NULL)
		str = "(null)";
	return (_print_rev_recursion(str, length));
}

/**
 * print_base16 - prints number in base 16 recursively
 * @value: The number to be printed
 * @length: The amount of digits to be printed.
 * Return: length
 */
int print_base16(unsigned int value, int length)
{
	if (value / 16)
		length = print_base16(value / 16, length + 1);
	if (value % 16 < 10)
		_putchar(value % 16 + 48);
	else
		_putchar(value % 16 + 55);
	return (length);
}

/**
 * print_hexa - From decimal to hexadecimal
 * @params: The name for va_list
 * Return: number length or -1 on error.
 */
int print_hexa(va_list *params)
{
	int length = 0, negative = 0;
	unsigned int value = va_arg(*params, unsigned int);

	length = print_base16(value, length) + negative + 1;
	return (length);
}

/**
 * print_base16_mini - prints number in base 16 recursively
 * @value: The number to be printed
 * @length: The amount of digits to be printed
 * Return: length
 */
int print_base16_mini(unsigned int value, int length)
{
	if (value / 16)
		length = print_base16_mini(value / 16, length + 1);
	if (value % 16 < 10)
		_putchar(value % 16 + 48);
	else
		_putchar(value % 16 + 87);
	return (length);
}

/**
 * print_mini_hexa - from decimal to lowercase hexadecimal
 * @params: va_list
 * Return: number length, -1 on error
 */
int print_mini_hexa(va_list *params)
{
	int length = 0, negative = 0;
	unsigned int value = va_arg(*params, unsigned int);

	length = print_base16_mini(value, length) + negative + 1;
	return (length);
}

/**
 * print_special - writes the character c
 * @params: va_list
 * Return: 1, -1 on error
 */
int print_special(va_list *params)
{
	char c = va_arg(*params, int);

	return (c + 0);
}
