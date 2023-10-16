#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * Return -  the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	while (*format) 
	{
	if (*format != '%')
	{
	putchar(*format);
	count++;
	}
	else
	{
	format++;
	switch (*format)
	{
	case 'c':
	{

	char c = va_arg(args, int);
	putchar(c);
	count++;
	break;
	}
	case 's':
	{

	const char *str = va_arg(args, const char *);
	while (*str)
	{
	putchar(*str);
	str++;
	count++;
	}
	break;
	}
	case '%':
	putchar('%');
	count++;
	break;
	default:
	putchar('%');
	putchar(*format);
	count += 2;
	}
	}
	format++;
	}

	va_end(args);
	return (count);
}

int main(void)
{
	int num = 42;
	char ch = 'A';

	_printf("Hello, %s! The number is %d%%. Character: %c\n", "world", num, ch);

	return (0);
}

