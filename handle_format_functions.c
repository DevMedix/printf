#include "main.h"

/**
 * _get_format - gets the format of given string
 * @fmt: format string
 * Return: returns the formatted string
 */
char *_get_format(const char *fmt)
{
	int j;
	char *convert;

	j = 0;
	while (no_conversion(fmt[j]) && fmt[j])
		++j;
	if (no_conversion(fmt[j]))
	{
		return (NULL);
	}
	convert = malloc((j + 2) * sizeof(char));
	convert = _strncpy(convert, fmt, j + 1);
	convert[j + 1] = '\0';
	return (convert);
}


/**
 * _format_filler - fills in the format_array with all conversion formatters
 * including their flags
 * @fmt: format string containing possible formatters
 * Return: array of the format
 */

void _format_filler(const char *fmt)
{
	int i, l_convert, flag;
	char *convert;

	flag = 0;
	for (i = 0; fmt[i] != '\0'; ++i)
	{
		if (fmt[i] == '%')
		{
			flag = 1;
			if (fmt[i + 1] == '%')
			{
				flag = 0;
				i += 1;
			}
		}
		if (flag == 1)
		{
			flag = 0;
			convert = _get_format(fmt + i);
			l_convert = _strlen(convert);
			get_validity_func(convert[l_convert - 1])(convert);
			free(convert);
			i += l_convert - 1;

		}
	}
}

