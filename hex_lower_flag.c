#include "main.h"

/**
 * _print_hex_lower - prints binary
 * @valist: va_list variable
 * @buf: buffer
 * @f: flag
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */
int _print_hex_lower(va_list valist, char buf[], int f, int w, int p, int s)
{
	return (_print_hex_num(valist, "0123456789abcdef", buf, f, 'x', w, p, s));
}
