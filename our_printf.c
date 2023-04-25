#include "main.h"

void _check_buffer(char buf[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int f, w, p, s, buff_ind = 0;
	va_list valist;
	char buf[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(valist, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buf[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				_check_buffer(buf, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			_check_buffer(buf, &buff_ind);
			f = _retrieve_flag(format, &i);
			w = _check_width_flag(format, &i, valist);
			p = _check_precision_flag(format, &i, valist);
			s = _check_size_flag(format, &i);
			++i;
			printed = _print_flag_handlers(format, &i, valist, buf, f, w, p, s);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	_check_buffer(buf, &buff_ind);

	va_end(valist);

	return (printed_chars);
}

/**
 * _check_buffer - Prints the contents of the buffer if it exist
 * @buf: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void _check_buffer(char buf[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buf[0], *buff_ind);

	*buff_ind = 0;
}

