#include "main.h"


/**
 * _binary_conversion - validates binaries
 * @str: format string
 * Return: 1 if checks else 0
 */
int _binary_conversion(char *str)
{
	(void) str;

	return (1);
}



/**
 * _create_binary - make an octal string
 * @str: a format string
 * @valist: va_list variable
 * Return: returns pointer to the result
 */
char *_create_binary(char *str, va_list valist)
{
	unsigned int num;
	char *res;
	(void) str;

	num = va_arg(valist, unsigned int);
	res = convert_2octa(num, 2);
	return (res);
}

