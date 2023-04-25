#include "main.h"

/**
 * _check_size_flag - A funct that checks size
 * @format: Format
 * @i: Integer pointer
 *
 * Return: Integer
 */
int _check_size_flag(const char *format, int *i)
{
	int curr_index = *i + 1;
	int s = 0;

	if (format[curr_index] == 'l')
		s = S_LONG;
	else if (format[curr_index] == 'h')
		s = S_SHORT;

	if (s == 0)
		*i = curr_index - 1;
	else
		*i = curr_index;

	return (s);
}
