#include "main.h"

/**
 * _check_no_print - prints binary
 * @valist: va_list variable
 * @buf: buffer
 * @f: flag
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */
int _check_no_print(va_list valist, char buf[], int f, int w, int p, int s)
{
	int i = 0, offset = 0;
	char *str = va_arg(valist, char *);

	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (_check_can_print(str[i]))
			buf[i + offset] = str[i];
		else
			offset += _join_hex(str[i], buf, i + offset);

		i++;
	}

	buf[i + offset] = '\0';

	return (write(1, buf, i + offset));
}
