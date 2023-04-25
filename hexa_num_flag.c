#include "main.h"

/**
 * _print_hex_num - prints binary
 * @valist: va_list variable
 * @map_to: map variable
 * @f_ch: char flag
 * @buf: buffer
 * @f: flag
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */
int _print_hex_num(va_list valist, char map_to[],
char buf[], int f, char f_ch, int w, int p, int s)
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
		buf[i--] = map_to[num % 16];
		num /= 16;
	}

	if (f & F_HASH && init_num != 0)
	{
		buf[i--] = f_ch;
		buf[i--] = '0';
	}

	i++;

	return (_print_unsignd(0, i, buf, f, w, p, s));
}
