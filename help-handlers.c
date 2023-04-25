#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * format_precision - Returns the right format precision
 * @s: The format string;
 * @format: Format character
 * Return: Precision numb of -1 if it does not exist
 */

int format_precision(char *s, char format)
{
	int t, i;

	t = 0;
	for (i = 0; s[i] != format; i++)
	{
		if (s[i] == '.')
		{
			i++;
			while (s[i] != format)
			{
				t = 10 * t + s[i] - '0';
				i++;
			}
			if (t == 0)
				return (-1);
			break;
		}
	}
	return (t);
}

/**
 * width_handler - Returns the correct width
 * @s: The format string;
 * @format: format of str to check
 * Return: width or -1 if width does not exist
 */

int width_handler(char *s, char format)
{
	int width, i;

	i = 1;
	width = 0;
	while ((s[i] != '.' || s[i] != format) && _is_digit(s[i]))
	{
		width = 10 * width + s[i] - '0';
		i++;
	}
	return (width);
}

/**
 * ptr_result- Returns a pointer back to results
 * @arr: Array
 * @s: String
 * @pres: Precision
 * @width: Width
 * @slen: String length
 * @flen: format length
 * @mlen: Malloc length
 * Return: Pointer to array result
 */

char *ptr_result(char *arr, char *s, int pres, int width
, int slen, int flen, int mlen)
{
	int t, k, i;

	t = k = i = 0;

	if (pres > 0 && width > 0)
	{
		for (t = 0; t < (slen - pres); t++)
			arr[t] = ' ';
		for (k = 0; k < pres; k++, t++)
			arr[t] = s[k];
		arr[t] = '\0';
	}
	else if (pres == 0 && width == 0 && flen == 2)
	{
		for (t = 0; s[t] != '\0'; t++)
			arr[t] = s[t];
		arr[t] = '\0';
	}
	else if (pres == -1)
	{
		arr[t] = '\0';
	}
	else
	{
		for (t = 0; t < (width - slen); t++)
			arr[t] = ' ';
		for (k = k + t, i = 0; k < mlen && s[i] != '\0'; k++, i++)
			arr[k] = s[i];
		arr[k] = '\0';
	}
	return (arr);

}
