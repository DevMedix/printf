#include "main.h"

/**
 * _print_integer_flag - prints binary
 * @valist: va_list variable
 * @buf: buffer
 * @f: flag
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */
int _print_integer_flag(va_list valist, char buf[], int f, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	int chk_negative = 0;
	long int n = va_arg(valist, long int);
	unsigned long int num;

	n = _number_size_converter(n, s);

	if (n == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		chk_negative = 1;
	}

	while (num > 0)
	{
		buf[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (_print_number(chk_negative, i, buf, f, w, p, s));
}
