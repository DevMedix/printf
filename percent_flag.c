#include "main.h"

/**
 * _print_percent_flag - prints percent
 * @valist: va_list variable
 * @buf: buffer
 * @f: flag
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */
int _print_percent_flag(va_list valist, char buf[], int f, int w, int p, int s)
{
	UNUSED(valist);
	UNUSED(buf);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);
	return (write(1, "%%", 1));
}
