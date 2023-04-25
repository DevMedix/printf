#include "main.h"
/**
 * _print_flag_handlers - prints binary
 * @fmt: format
 * @ind: index
 * @valist: va_list variable
 * @buf: buffer
 * @f: flag
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */
int _print_flag_handlers(const char *fmt, int *ind, va_list valist,
char buf[], int f, int w, int p, int s)
{
	int i, un_len = 0, prnt_chr = -1;
	fmt_t fmt_types[] = {
		{'c', _char_flag}, {'s', _print_str_flag}, {'%', _print_percent_flag},
		{'i', _print_integer_flag}, {'d', _print_integer_flag}, {'b', _binary_flag},
		{'u', _print_unsigned_flag}, {'o', _print_octal_flag},
		{'x', _print_hex_lower},
		{'X', _print_hex_upper}, {'p', _print_pointer_flag}, {'S', _check_no_print},
		{'r', _print_reverse_flag}, {'R', _print_rot}, {'\0', NULL}
	};

	i = 0;

	while (fmt_types[i].fmt != '\0')
	{
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(valist, buf, f, w, p, s));
		i++;
	}

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		un_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			un_len += write(1, " ", 1);
		else if (w)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		un_len += write(1, &fmt[*ind], 1);
		return (un_len);
	}
	return (prnt_chr);
}


