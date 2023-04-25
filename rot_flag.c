#include "main.h"

/**
 * _print_rot - prints rot
 * @valist: va_list variable
 * @buf: buffer
 * @f: flag
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */
int _print_rot(va_list valist, char buf[], int f, int w, int p, int s)
{
	char xtr;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in_str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out_str[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(valist, char *);
	UNUSED(buf);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in_str[j]; j++)
		{
			if (in_str[j] == str[i])
			{
				xtr = out_str[j];
				write(1, &xtr, 1);
				count++;
				break;
			}
		}
		if (!in_str[j])
		{
			xtr = str[i];
			write(1, &xtr, 1);
			count++;
		}
	}
	return (count);
}
