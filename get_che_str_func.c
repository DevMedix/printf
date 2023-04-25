#include "main.h"

/**
 * get_che_str_func - selects the correct validity func to perform
 * @c: formatter passed
 * Return: a pointer to function given formatter
 */

char *(*get_che_str_func(char c))(char *, va_list)
{
	che_str check[] = {
		{'c', _create_char},
		{'s', str_make},
		{'d', _create_decimal},
		{'i', _create_decimal},
		{'u', make_unsigned},
		{'x', make_hex},
		{'X', _create_hex_upper},
		{'b', _create_binary},
		{'o', make_octal}
	};
	int i;

	i = 0;
	for (; i < 9; i++)
	{
		if (c == check[i].type)
			return (check[i].make_s);
	}
	return (NULL);
}

