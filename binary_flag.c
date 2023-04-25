#include "main.h"
/**
 * _binary_flag - prints binary
 * @valist: va_list variable
 * @buf: buffer
 * @f: flag
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */
int _binary_flag(va_list valist, char buf[], int f, int w, int p, int s)
{
	unsigned int n, m, i, add;
	unsigned int a[32];
	int num;

	UNUSED(buf);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	n = va_arg(valist, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;

	i = 1;

	while (i < 32)
	{
		m /= 2;
		a[i] = (n / m) % 2;
		i++;
	}


	for (i = 0, add = 0, num = 0; i < 32; i++)
	{
		add += a[i];
		if (add || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			num++;
		}
	}
	return (num);
}


