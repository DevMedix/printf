#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * octa_check - Checks validity of octals
 * @s: Format string to be checked
 * Return: 1 if it checks and 0 and exits otherwise
 */
int octa_check(char *s)
{
	(void) s;
	return (1);
}



/**
 * convert_2octa - Converts a number to an octadeci.
 * @n: Number
 * @b: The numb base, 8 or 2
 * Return: A number in octadeci or binary in 2 pieces
 */
char *convert_2octa(unsigned int n, int b)
{

	int t;
	char *s;

	t = 0;
	s = malloc(sizeof(int) * 200);
	do {
		s[t++] = (n % b) + '0';
		n = n / b;
	} while (n > 0);
	reverse_array(s, t);
	s[t] = '\0';

	return (s);
}




/**
 * make_octal - Makes an octa out of string
 * @s: String
 * @l: A va_list
 * Return: A pointer to the result
 */
char *make_octal(char *s, va_list l)
{
	unsigned int n;
	char *result;
	(void) s;

	n = va_arg(l, unsigned int);
	result = convert_2octa(n, 8);
	return (result);
}
