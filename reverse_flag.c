#include "main.h"

/**
 * _print_reverse_flag - A funct that prints reverse
 * @valist: Va_list variable
 * @buf: Buffer
 * @f: Flag
 * @w: Width
 * @p: Precision
 * @s: Size
 *
 * Return: Integer
 */
int _print_reverse_flag(va_list valist, char buf[],
	int f, int w, int p, int s)
{
	char *str;
	int i, count = 0;

	UNUSED(buf);
	UNUSED(f);
	UNUSED(w);
	UNUSED(s);

	str = va_arg(valist, char *);

	if (str == NULL)
	{
		UNUSED(p);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

