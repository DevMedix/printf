#include "main.h"

/**
 * _check_precision_flag - checks precision
 * @valist: va_list variable
 * @i: integer pointer
 * @format: format
 *
 * Return: int
 */
int _check_precision_flag(const char *format, int *i, va_list valist)
{
	int curr_index = *i + 1;
	int p = -1;

	if (format[curr_index] != '.')
		return (p);

	p = 0;

	for (curr_index += 1; format[curr_index] != '\0'; curr_index++)
	{
		if (_check_is_digit(format[curr_index]))
		{
			p *= 10;
			p += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*')
		{
			curr_index++;
			p = va_arg(valist, int);
			break;
		}
		else
			break;
	}

	*i = curr_index - 1;

	return (p);
}
