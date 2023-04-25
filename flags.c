#include "main.h"

/**
 * _retrieve_flag - prints binary
 * @fmt: format
 * @i: integer
 *
 * Return: int
 */
int _retrieve_flag(const char *fmt, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_index;
	int f = 0;
	const char FLAGS_CHR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_index = *i + 1; fmt[curr_index] != '\0'; curr_index++)
	{
		for (j = 0; FLAGS_CHR[j] != '\0'; j++)
			if (fmt[curr_index] == FLAGS_CHR[j])
			{
				f |= FLAGS_ARRAY[j];
				break;
			}

		if (FLAGS_CHR[j] == 0)
			break;
	}

	*i = curr_index - 1;

	return (f);
}
