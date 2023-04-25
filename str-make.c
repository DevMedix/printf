#include <stdarg.h>
#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * str_make - A funct that creates formatted string
 * @s: Str
 * @vl: Arg
 * Return: Formatted str
 */

char *str_make(char *s, va_list vl)
{
	int p, w, slen, mlen, flen, t, k;
	char *result, *string;

	slen = mlen = t = k = 0;
	string = va_arg(vl, char *);
	if (string == NULL)
		exit(98);
	p = format_precision(s, 's');
	w = width_handler(s, 's');
	slen = _strlen(string);
	flen = _strlen(s);

	if (w > p && w != 0 && p != -1)
		mlen = w;
	else if (p > w && p != 0)
		mlen = p;
	else
		mlen = slen;
	result = malloc(sizeof(char) * (mlen + 1));
	result = ptr_result(result, string, p, w, slen, flen, mlen);
	return (result);
}


/**
 * convert_str - Checks if format is right
 * @s: Char being checked
 * Return: 1 if it is 0 otherwise
 */
int convert_str(char *s)
{
	int i;
	int flag;

	i = (*s == '%') ? 1 : 0;
	flag = 0;

	while (*(s + i) != 's')
	{
		if ((_is_digit(*(s + i)) == 0 && *(s + i) != '.') ||
		    (*(s + i) == '.' && flag))
		{
			return (0);
		}
		if (_is_digit(*(s + i)) == 0 && *(s + i) == '.')
		{
			flag = 1;
			++i;
		}
		i++;
	}
	return (1);
}

