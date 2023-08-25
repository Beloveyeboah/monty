#include "monty.h"
#include <stdlib.h>

/**
 * get_int - gets a character pointer
 * @num: number to convert to string
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	char *ret;
	long num_l = 0;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);
	if (num < 0 || num_l < 0)
	{
		length++;
	}
	ret = malloc(length + 1);
	if (!ret)
	{
		return (NULL);
	}
	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';
	return (ret);
}

/**
 * get_numbase_len - gets length of buffer needed for an unsigned int
 * @num: number to get length needed
 * @base: base of number representation
 * Return: integer containing length of
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}


/**
 * _abs - gets the absolute value of an
 * @i: integer to get absolute value
 * Return: unsigned integer abs rep i
 */
unsigned int _abs(int i)
{
	if (i < 0)
	{
		return (-(unsigned int)i);
	}
	return ((unsigned int)i);
}

/*
 * fill_numbase_buff - fills buffer with correct numbers up to base
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 * Return: always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
		{
			buff[i] = rem + 87;
		}
		else
		{
			buff[i] = rem + '0';
		}
		num /= base;
		i--;
	}
}
