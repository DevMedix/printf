#include "main.h"

/**
 * _check_can_print - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int _check_can_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * _join_hex - Append ascci in hexadecimal code to buffer
 * @buf: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int _join_hex(char ascii_code, char buf[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buf[i++] = '\\';
	buf[i++] = 'x';

	buf[i++] = map_to[ascii_code / 16];
	buf[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * _check_is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _check_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * _number_size_converter - Casts a number to the specified size
 * @num: Number to be casted.
 * @s: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int _number_size_converter(long int num, int s)
{
	if (s == S_LONG)
		return (num);
	else if (s == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * _unsigned_size_converter - Casts a number to the specified size
 * @num: Number to be casted
 * @s: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int _unsigned_size_converter(unsigned long int num, int s)
{
	if (s == S_LONG)
		return (num);
	else if (s == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
