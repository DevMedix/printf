#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * error_f - Returns error
 * @format: Format
 */

void error_f(const char *format)
{
	if (!format || !*format)
	{
		write(1, "error", 6);
		exit(98);
	}
}

/**
 * _printf - Our printf copy
 * @format: String format
 * Return: Numb of chars printed
 */

int _printf(const char *format, ...)
{
	int i, b, l_conv, flag;
	char *buffer, *conv, *format_str;
	va_list alist;

	error_f(format);
	buffer = malloc(BUF_LENGTH * sizeof(char));
	_flush(buffer);
	va_start(alist, format), flag = b = 0;
	for (i = 0; format[i] != '\0';)
	{
		if (format[i] != '%')
		{
			fill_buffer(buffer, format + i, b, 1);
			i += 1, b += 1;
		}
		if (format[i] == '%')
		{
			flag = 1, conv = grab_format(format + i);
			if (format[i + 1] == '%' || conv == NULL)
			{
				flag = (flag == 0) ? 1 : 0;
				fill_buffer(buffer, format + i, b, 1);
				i += 2, b += 1;
			}
		}
		if (flag == 1)
		{
			flag = 0;
			conv = grab_format(format + i);
			l_conv = _strlen(conv);
			format_str = get_mstring_func(conv[l_conv - 1])(conv, alist);
			free(conv);
			fill_buffer(buffer, format_str, b, _strlen(format_str));
			b = b + _strlen(format_str);
			free(format_str), i += l_conv;
		}
	}
		print_buffer(buffer, b);
		free(buffer);
		return (b);
}
