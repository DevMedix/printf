#include "main.h"
/**
 * _create_char - create string from char
 * @str: string format
 * @valist: va_list variable
 * Return: returns the string
 */
char *_create_char(char *str, va_list valist)
{
	int i, j;
	char *res;

	i = 0;
	j = (*str == '%') ? 1 : 0;
	while (*(str + j) != 'c' && _is_digit(*(str + j)))
	{
		i = 10 * i + *(str + j) - '0';
		++str;
	}

	if (i == 0)
		i += 1;
	res = malloc((i + 1) * sizeof(char));

	j = 0;

	while (j < (i - 1))
	{
		res[j] = ' ';
		++j;
	}
	res[j] = va_arg(valist, int);
	res[i] = '\0';
	return (res);
}


/**
 * _convert_char - check for correct format
 * @str: format string to char
 * Return: 1 if it is successful else 0
 */
int _convert_char(char *str)
{
	int i;

	i = (*str == '%') ? 1 : 0;
	if (*(str + i) == '0')
	{
		write(1, "no valid char format\n", 21);
		exit(98);
		return (0);
	}
	while (*(str + i) != 'c')
	{
		if (_is_digit(*(str + i)) == 0)
		{
			write(1, "no valid char format\n", 21);
			exit(98);
			return (0);
		}
		++i;
	}
	return (1);
}

