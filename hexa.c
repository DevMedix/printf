#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * conversion_h - Checks validity of hex
 * @s: Str being checked
 * Return: 1 if checks is positive and 0 and exits otherwise
 */
int conversion_h(char *s)
{
	(void) s;
	return (1);
}



/**
 * hex - A funct that converts a number to an hex
 * @n: Numb to be converted
 * Return: A numb in octal
 */
char *hex(unsigned int n)
{
	int i;
	char c[16] = "0123456789abcdef";
	char *mem;

	i = 0;
	ns = malloc(sizeof(char) * 100);
	do {
		mem[i++] = (c[n % 16]);
		n = n / 16;
	} while (n > 0);
	reverse_array(mem, i);
	mem[i] = '\0';
	return (mem);
}

/**
 * make_hex - A funct that makes an hex
 * @s: String
 * @l: A va_list
 * Return: A pointer to the result
 */
char *make_hex(char *s, va_list l)
{
	unsigned int t;
	char *result;
	(void) s;
	t = va_arg(l, unsigned int);
	result = hex(t);
	return (result);
}


/**
 * reverse_array - A funct that reverses an array of ints
 * @a: Array;
 * @n: Number of elements in the array
 */

void reverse_array(char *a, int n)
{
	int i;
	int mem;

	i = 0;
	n = n - 1;
	while (i <= n)
	{
		mem = a[i];
		a[i] = a[n];
		a[n] = temp;
		i++;
		n--;
	}
}
