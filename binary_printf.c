#include <stdio.h>
#include <stdarg.h>

/*
 * binary_printf: converts an integer to a binary string.
 * n: The integer to convert.
 * binary: The buffer to store the binary representation.
 *
 * Returns: always the length of the binary string.
 */


int convert_to_binary(int n, char binary[])
{
	if (n == 0)

	{
	binary[0] = '0';
	binary[1] = '\0';
	return (1);
	}

	int i = 0;

	while (n > 0)

	{
	binary[i] = (n % 2) + '0';
	n = n / 2;
	i++;
	}

	int len = i;

	binary[i] = '\0';

	for (int j = 0; j < len / 2; j++)
	{

	char temp = binary[j];

	binary[j] = binary[len - j - 1];
	binary[len - j - 1] = temp;
	}

	return (len);
}

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
	if (*format == 'b')

	{

	int num = va_arg(args, int);
	char binary[32];
	int len = convert_to_binary(num, binary);

	fputs(binary, stdout);
	count += len;
	}
	else
	{
	putchar('%');
	count++;
	}
	}
	format++;
	}

	va_end(args);
	return (count);
	}

int main(void)

{
	_printf("%b\n", 98);
	return (0);
}

