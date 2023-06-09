#include "main.h"

/**
 * _print_unsigned_flag - A funct that prints unsigned num
 * @valist: Va_list variable
 * @buf: Buffer
 * @f: Flag
 * @w: Width
 * @p: Precision
 * @s: Size
 *
 * Return: Integer
 */
int _print_unsigned_flag(va_list valist, char buf[],
int f, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(valist, unsigned long int);

	num = _unsigned_size_converter(num, s);

	if (num == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buf[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (_print_unsignd(0, i, buf, f, w, p, s));
}
