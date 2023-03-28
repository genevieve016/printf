#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int i = list->i;

	if (format[i] == '.')
	{
		i++;
		if (format[i] == '*')
		{
			i++;
			list->precision = va_arg(list->args, int);
		}
		else
		{
			list->precision = 0;
			while (_isdigit(format[i]))
				list->precision = list->precision * 10 + format[i++] - '0';

		}
	}

	return (i);
}
