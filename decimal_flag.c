#include "main.h"

/**
 * _convert_di - validates decimal (d) and integer (i)
 * @str: format string ot check
 * Return: 1 if checks and 0 and exits otherwise
 */
int _convert_di(char *str)
{
	(void) str;
	return (1);
}

/**
 * _aoti - converts an integer to string
 * @num: integer
 * Return: returns a string
 */
char *_aoti(int num)
{
	int len, tens, i, minimal;
	char *number;

	len = 2;
	minimal = 1;
	if (num >= 0)
	{
		len = len - 1;
		minimal = 0;
		num = -num;
	}
	tens = num;
	while (tens < -9)
	{
		tens /= 10;
		len = len + 1;
	}
	number = malloc((len + 1) * sizeof(char));
	i = len - 1;
	number[len] = '\0';

	do {
		number[i] = -(num % 10) + '0';
		num /= 10;
		--i;
	} while (i >= 0 && num < 0);

	if (i == 0 && minimal)
		number[0] = '-';

	return (number);
}

/**
 * _create_decimal - creates formatted output
 * @str: format string
 * @valist: va_list variable
 * Return: formatted string;
 */

char *_create_decimal(char *str, va_list valist)
{
	char *number;
	int num;
	(void) str;

	num = va_arg(valist, int);
	number = _aoti(num);
	return (number);
}

