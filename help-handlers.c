#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * format_precision - A funct that returns the appropriate precision
 * @s: format string;
 * @formatter: formatter
 * Return: precision number of -1 if it doesnt exist
 */

int format_precision(char *s, char formatter)
{
	int p, i;

	p = 0;
	for (i = 0; s[i] != formatter; i++)
	{
		if (s[i] == '.')
		{
			i++;
			while (s[i] != formatter)
			{
				p = 10 * p + s[i] - '0';
				i++;
			}
			if (p == 0)
				return (-1);
			break;
		}
	}
	return (p);
}

/**
 * width_handler - A funct that returns the appropriate width
 * @s: format string;
 * @formatter: formatter to check
 * Return: width or -1 if width doesnt exist
 */

int width_handler(char *s, char formatter)
{
	int w, i;

	i = 1;
	w = 0;
	while ((s[i] != '.' || s[i] != formatter) && _is_digit(s[i]))
	{
		w = 10 * w + s[i] - '0';
		i++;
	}
	return (w);
}

/**
 * ptr_result - A that gives a pointer back to results
 * @r: array
 * @s: string
 * @p: precision
 * @w: width
 * @slen: str len
 * @flen: format len
 * @mlen: malloc len
 * Return: result pointer
 */

char *ptr_result(char *r, char *s, int p, int w, int slen, int flen, int mlen)
{
	int t, k, i;

	t = k = i = 0;

	if (p > 0 && w > 0)
	{
		for (t = 0; t < (slen - p); t++)
			r[t] = ' ';
		for (k = 0; k < p; k++, t++)
			r[t] = s[k];
		r[t] = '\0';
	}

	else if (p == 0 && w == 0 && flen == 2)
	{
		for (t = 0; s[t] != '\0'; t++)
			r[t] = s[t];
		r[t] = '\0';
	}

	else if (p == -1)
	{
		r[t] = '\0';
	}
	else
	{
		for (t = 0; t < (w - slen); t++)
			r[t] = ' ';
		for (k = k + t, i = 0; k < mlen && s[i] != '\0'; k++, i++)
			r[k] = s[i];
		r[k] = '\0';
	}
	return (r);
}
