#include "main.h"

/**
 * _print_pointer_flag - prints pointer
 * @valist: va_list variable
 * @buf: buffer
 * @f: flag
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */
int _print_pointer_flag(va_list valist, char buf[], int f, int w, int p, int s)
{
	char xtr_chr = 0, padin = ' ';
	int index = BUFF_SIZE - 2, len = 2, padin_strt = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(valist, void *);

	UNUSED(w);
	UNUSED(s);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buf[BUFF_SIZE - 1] = '\0';
	UNUSED(p);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buf[index--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((f & F_ZERO) && !(f & F_MINUS))
		padin = '0';
	if (f & F_PLUS)
		xtr_chr = '+', len++;
	else if (f & F_SPACE)
		xtr_chr = ' ', len++;

	index++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (_print_pointer(buf, index, len, w, f, padin, xtr_chr, padin_strt));
}
