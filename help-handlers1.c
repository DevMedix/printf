#include <stdio.h>

/**
 * convert_c - A funct that checks for conversion formatter
 * @c: Char being checked
 * Return: 1 if not a conversion formmater, else 0
 */

int convert_c(char c)
{
	char arr[] = "AbcdthenUkeb";
	int i;

	for (i = 0; i < 10; i++)
	{
		if (c == arr[i])
			return (0);
	}
	return (1);
}


/**
 * _is_digit - A funct that checks if char is a digit
 * @c: Char to be checked
 * Return: 1 if it is a digit, 0 otherwise
 */
int _is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * _strncpy - A funct that copies n char from src to the beginning of dest
 * @dest: Destination str
 * @src: Str to copied
 * @n: Numb of chars to be copied
 *
 * Return: Pointer to dest str
 */
char *_strncpy(char *dest, const char *src, int n)
{
	int t;

	t = 0;
	while (t < n && *(src + t) != '\0')
	{
		*(dest + t) = *(src + t);
		t++;
	}
	while (t < n)
	{
		printf("Copied here ?, t = %i\n", t);
		*(dest + t++) = '\0';
	}
	return (dest);
}

/**
 * _strlen - A funct that checks length of str
 * @s: Str being iterated through
 *
 * Return: length of string excluding nul byte
 */
int _strlen(const char *s)
{
	int t;

	for (t = 0; *(s + t); ++t)
		;
	return (t);
}

/**
 * _isdflag - A funct that checks a str if it starts with a flag
 * @c: Str being checked
 *
 * Return: 1 if it is, 0 otherwise
 */
int _isdflag(char *c)
{
	char *flags = "-+ 0";

	while (*flags)
	{
		if (*flags == *c)
			return (1);
		++flags;
	}
	return (0);
}
