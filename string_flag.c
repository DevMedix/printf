#include "main.h"

/**
 * _print_str_flag - A function that prints string
 * @valist: Va_list variable
 * @buf: Buffer
 * @f: Flag
 * @w: Width
 * @p: Precision
 * @s: Size
 *
 * Return: Integer
 */
int _print_str_flag(va_list valist, char buf[], int f, int w, int p, int s)
{
	int len = 0, i;
	char *str = va_arg(valist, char *);

	UNUSED(buf);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);
	if (str == NULL)
	{
		str = "(null)";
		if (p >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (p >= 0 && p < len)
		len = p;

	if (w > len)
	{
		if (f & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (w);
		}
	}

	return (write(1, str, len));
}
