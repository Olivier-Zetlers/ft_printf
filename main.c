#include "ft_printf.h"

int main(void)
{
	char *str = "world";
	char c = '!';
	ft_printf("Hello %s %c. Here is a memory address: %p \n", str, c, &c);
	write(1, "\n", 1);
	printf("Memory address should be %p\n", &c);
	return 0;
} 
