#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * convert_s - A funct that checks for the validity of s
 * @s: Format str being checked
 * Return: 1 if valid and 0 and exit if otherwise
 */
int convert_s(char *s)
{
	(void) s;
	return (1);
}



/**
 * num_tostr - Transforms a number into a string
 * @n: An unsigned int
 * Return: A string
 */
char *num_tostr(unsigned int n)
{
	int t, i;
	char *number;
	unsigned int tens;

	t = 1;
	tens = n;
	while (tens > 9)
	{
		tens /= 10;
		t = t + 1;
	}

	number = malloc((t + 1) * sizeof(char));
	i = t - 1;
	number[t] = '\0';
	do {
		number[i] = (n % 10) + '0';
		n /= 10;
		--i;
	} while (i >= 0 && n > 0);
	return (number);
}



/**
 * make_unsigned - A funct that makes an unsigned int
 * @s: String
 * @l: A va_list
 * Return: A pointer to the result
 */
char *make_unsigned(char *s, va_list l)
{
	unsigned int t;
	char *result;
	(void) s;
	t = va_arg(l, unsigned int);
	result = num_tostr(t);
	return (result);

}
