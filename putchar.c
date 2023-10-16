#include "printf.h"

int main(void) 
{
	_printf("%b\n", 98);
	
	int num = 42;
	char ch = 'A';
	_printf("Hello, %s! The number is %d%%. Character: %c\n", "world", num, ch);

	return (0);
}
