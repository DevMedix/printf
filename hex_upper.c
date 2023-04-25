#include "main.h"

/**
 * _hex_upper - convert a number to an octal
 * @n: a number
 * Return: a number in octal
 */
char *_hex_upper(unsigned int n)
{
	int i;
	char str[16] = "0123456789ABCDEF";
	char *num_str;

	i = 0;
	num_str = malloc(sizeof(char) * 100);
	do {
		num_str[i++] = (str[n % 16]);
		n = n / 16;
	} while (n > 0);
	reverse_array(num_str, i);
	num_str[i] = '\0';
	return (num_str);
}

/**
 * _create_hex_upper - make an octal string
 * @str: a format string
 * @valist: va_list variable
 * Return: a pointer to the result
 */
char *_create_hex_upper(char *str, va_list valist)
{
	unsigned int num;
	char *res;
	(void) str;
	num = va_arg(valist, unsigned int);
	res = _hex_upper(num);
	return (res);
}

