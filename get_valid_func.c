#include "main.h"

/**
 * get_valid_func - selects the correct validity func to perform
 * @c: formatter passed
 * Return: a pointer to function given formatter
 */

int (*get_valid_func(char c))(char *)
{
	valid check_v[] = {
		{'c', _convert_char},
		{'s', conversion_string},
		{'d', _convert_di},
		{'i', _convert_di},
		{'u', conversion_u},
		{'x', conversion_h},
		{'X', conversion_h},
		{'b', _binary_conversion},
		{'o', conversion_o}
	};
	int i;

	i = 0;
	for (; i < 9; i++)
	{
		if (c == check_v[i].type)
			return (check_v[i].conver_check);
	}
	return (NULL);
}

