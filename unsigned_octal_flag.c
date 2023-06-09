#include "main.h"

/**
 * _print_octal_flag - A funct that prints unsigned octal
 * @valist: Va_list variable
 * @buf: Buffer
 * @f: Flag
 * @w: Width
 * @p: Precision
 * @s: Size
 *
 * Return: Integer
 */
int _print_octal_flag(va_list valist, char buf[], int f, int w, int p, int s)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(valist, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = _unsigned_size_converter(num, s);

	if (num == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buf[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (f & F_HASH && init_num != 0)
		buf[i--] = '0';

	i++;

	return (_print_unsignd(0, i, buf, f, w, p, s));
}
