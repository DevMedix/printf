#include "main.h"

/**
 * _char_print_handler - Prints a string
 * @c: char types.
 * @buf: Buffer array to handle print
 * @f:  Calculates active flags.
 * @w: get width.
 * @p: precision specifier
 * @s: Size specifier
 *
 * Return: Number of chars printed.
 */
int _char_print_handler(char c, char buf[], int f, int w, int p, int s)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padin = ' ';

	UNUSED(p);
	UNUSED(s);

	if (f & F_ZERO)
		padin = '0';

	buf[i++] = c;
	buf[i] = '\0';

	if (w > 1)
	{
		buf[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < w - 1; i++)
			buf[BUFF_SIZE - i - 2] = padin;

		if (f & F_MINUS)
			return (write(1, &buf[0], 1) +
					write(1, &buf[BUFF_SIZE - i - 1], w - 1));
		else
			return (write(1, &buf[BUFF_SIZE - i - 1], w - 1) +
					write(1, &buf[0], 1));
	}

	return (write(1, &buf[0], 1));
}


/**
 * _print_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buf: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width.
 * @p: precision specifier
 * @s: Size specifier
 *
 * Return: Number of chars printed.
 */
int _print_number(int is_negative, int ind, char buf[],
int f, int w, int p, int s)
{
	int len = BUFF_SIZE - ind - 1;
	char padin = ' ', extra_ch = 0;

	UNUSED(s);

	if ((f & F_ZERO) && !(f & F_MINUS))
		padin = '0';
	if (is_negative)
		extra_ch = '-';
	else if (f & F_PLUS)
		extra_ch = '+';
	else if (f & F_SPACE)
		extra_ch = ' ';

	return (_print_num_flag(ind, buf, f, w, p, len, padin, extra_ch));
}

/**
 * _print_num_flag - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buf: Buffer
 * @f: Flags
 * @w: width
 * @p: Precision specifier
 * @len: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int _print_num_flag(int ind, char buf[], int f, int w,
int p, int len, char padd, char extra_c)
{
	int i, padin_strt = 1;

	if (p == 0 && ind == BUFF_SIZE - 2 && buf[ind] == '0' && w == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (p == 0 && ind == BUFF_SIZE - 2 && buf[ind] == '0')
		buf[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (p > 0 && p < len)
		padd = ' ';
	while (p > len)
		buf[--ind] = '0', len++;
	if (extra_c != 0)
		len++;
	if (w > len)
	{
		for (i = 1; i < w - len + 1; i++)
			buf[i] = padd;
		buf[i] = '\0';
		if (f & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buf[--ind] = extra_c;
			return (write(1, &buf[ind], len) + write(1, &buf[1], i - 1));
		}
		else if (!(f & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buf[--ind] = extra_c;
			return (write(1, &buf[1], i - 1) + write(1, &buf[ind], len));
		}
		else if (!(f & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buf[--padin_strt] = extra_c;
			return (write(1, &buf[padin_strt], i - padin_strt) +
				write(1, &buf[ind], len - (1 - padin_strt)));
		}
	}
	if (extra_c)
		buf[--ind] = extra_c;
	return (write(1, &buf[ind], len));
}

/**
 * _print_unsignd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buf: Array of chars
 * @f: Flags specifiers
 * @w: Width specifier
 * @p: Precision specifier
 * @s: Size specifier
 *
 * Return: Number of written chars.
 */
int _print_unsignd(int is_negative, int ind,
char buf[], int f, int w, int p, int s)
{
	/* The number is stored at the bufer's right and starts at position i */
	int len = BUFF_SIZE - ind - 1, i = 0;
	char padin = ' ';

	UNUSED(is_negative);
	UNUSED(s);

	if (p == 0 && ind == BUFF_SIZE - 2 && buf[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (p > 0 && p < len)
		padin = ' ';

	while (p > len)
	{
		buf[--ind] = '0';
		len++;
	}

	if ((f & F_ZERO) && !(f & F_MINUS))
		padin = '0';

	if (w > len)
	{
		for (i = 0; i < w - len; i++)
			buf[i] = padin;

		buf[i] = '\0';

		if (f & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buf[ind], len) + write(1, &buf[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buf[0], i) + write(1, &buf[ind], len));
		}
	}

	return (write(1, &buf[ind], len));
}

/**
 * _print_pointer - Write a memory address
 * @buf: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @len: Length of number
 * @w: Width specifier
 * @f: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int _print_pointer(char buf[], int ind, int len, int w,
int f, char padd, char extra_c, int padd_start)
{
	int i;

	if (w > len)
	{
		for (i = 3; i < w - len + 3; i++)
			buf[i] = padd;
		buf[i] = '\0';
		if (f & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buf[--ind] = 'x';
			buf[--ind] = '0';
			if (extra_c)
				buf[--ind] = extra_c;
			return (write(1, &buf[ind], len) + write(1, &buf[3], i - 3));
		}
		else if (!(f & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buf[--ind] = 'x';
			buf[--ind] = '0';
			if (extra_c)
				buf[--ind] = extra_c;
			return (write(1, &buf[3], i - 3) + write(1, &buf[ind], len));
		}
		else if (!(f & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buf[--padd_start] = extra_c;
			buf[1] = '0';
			buf[2] = 'x';
			return (write(1, &buf[padd_start], i - padd_start) +
				write(1, &buf[ind], len - (1 - padd_start) - 2));
		}
	}
	buf[--ind] = 'x';
	buf[--ind] = '0';
	if (extra_c)
		buf[--ind] = extra_c;
	return (write(1, &buf[ind], BUFF_SIZE - ind - 1));
}
