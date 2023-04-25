#include "main.h"

/**
 * _print_hex_upper - prints binary
 * @valist: va_list variable
 * @buf: buffer
 * @f: flag
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */
int _print_hex_upper(va_list valist, char buf[], int f, int w, int p, int s)
{
	return (_print_hex_num(valist, "0123456789ABCDEF", buf, f, 'X', w, p, s));
}
