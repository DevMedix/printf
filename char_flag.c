#include "main.h"

/**
 * _char_flag - Prints a char
 * @valist: List a of arguments
 * @buf: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: Width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int _char_flag(va_list valist, char buf[], int f, int w, int p, int s)
{
	char chr = va_arg(valist, int);

	return (_char_print_handler(chr, buf, f, w, p, s));
}
