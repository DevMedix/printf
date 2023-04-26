#include "main.h"

/**
 * _check_width_flag - A funct that checks wiidth
 * @valist: Va_list variable
 * @format: Format
 * @i: Integer pointer
 * Return: Integer
 */
int _check_width_flag(const char *format, int *i, va_list valist)
{
	int curr_index;
	int w = 0;

	for (curr_index = *i + 1; format[curr_index] != '\0'; curr_index++)
	{
		if (_check_is_digit(format[curr_index]))
		{
			w *= 10;
			w += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*')
		{
			curr_index++;
			w = va_arg(valist, int);
			break;
		}
		else
			break;
	}

	*i = curr_index - 1;

	return (w);
}
