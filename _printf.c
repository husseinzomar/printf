#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	int no_of_char = 0;
	va_list arguments_list;

	if (format == NULL)
		return (-1);
	va_start(arguments_list, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			no_of_char++;
		}
		else
			format = format + 1;
		if (*format == '\0')
			break;
		if (*format == '%')
		{
			write(1, format, 1);
			no_of_char++;
		}
		else if (*format == 'c')
		{
			char c = va_arg(arguments_list, int);

			write(1, &c, 1);
			no_of_char++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(arguments_list, char*);

			write(1, str, strlen(str));
			no_of_char += strlen(str);
		}
	}
	format++;
	va_end(arguments_list);
	return (no_of_char);
}
