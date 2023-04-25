#include "main.h"
/**
 * _buffer_flush - fill the buffer with \0
 * @buffer: buffer;
 * The length of the buffer is defned in a macro
 * Return: pointer to buffer
 */
char *_buffer_flush(char *buffer)
{
	int num;

	num = 0;

	while (num < BUF_LENGTH)
	{
		buffer[num] = '\0';
		++num;
	}

	return (buffer);
}




/**
 * _buff_fill - fills buffer with string str
 * @buffer: buffer to fill
 * @str: string to fill the buffer
 * @count_c: chars put in buffer
 * @s_length: length of string
 * Return: pointer to buffer
 */
char *_buff_fill(char *buffer, const char *str, int count_c, int s_length)
{
	int num, _buffer_num;

	num = 0;
	_buffer_num = (count_c > BUF_LENGTH) ? count_c % BUF_LENGTH : count_c;
	while (num < s_length)
	{
		if (_buffer_num == BUF_LENGTH)
		{
			_write_buffer(buffer, BUF_LENGTH);
			buffer = _buffer_flush(buffer);
			_buffer_num = 0;
		}
		buffer[_buffer_num] = str[num];
		++num;
		++_buffer_num;
	}
	if (_buffer_num == BUF_LENGTH)
	{
		_write_buffer(buffer, BUF_LENGTH);
		buffer = _buffer_flush(buffer);
	}
	return (buffer);
}

/**
 * _write_buffer - prints the buffer
 * @buffer: buffer to print
 * @len: characters to print
 *
 * Return: void
 */
void _write_buffer(char *buffer, int len)
{

	if (len > BUF_LENGTH)
		len = len % BUF_LENGTH;
	write(1, buffer, len);
}

