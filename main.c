#include "ft_printf.h"

int main(void)
{
	int counter;	

	char *str1 = "world";
	char c1 = '!';
	int num1 = 42;

	counter = ft_printf("%c", c1);
	write(1, "\n", 1);
	printf("Number of characters printed with ft_printf above: %d\n", counter);


	counter = ft_printf("%s", str1);
	write(1, "\n", 1);
	printf("Number of characters printed with ft_printf above: %d\n", counter);

	counter = ft_printf("%d", num1);
	write(1, "\n", 1);
	printf("Number of characters printed with ft_printf above: %d\n", counter);

	counter = ft_printf("%i", num1);
	write(1, "\n", 1);
	printf("Number of characters printed with ft_printf above: %d\n", counter);

	counter = ft_printf("%p", &c1);
	write(1, "\n", 1);
	printf("Number of characters printed with ft_printf above: %d\n", counter);
	write(1, "\n", 1);
	printf("In test case above, memory address should be %p\n", &c1);

	write(1, "\n", 1);

	counter = ft_printf("Read the f... manual!\n");
	printf("Number of characters printed with ft_printf above (includes a NL): %d\n", counter);
	
	counter = ft_printf("Hello %s%c Hello %d%c Here's a memory address: %p but no NL", str1, c1, num1, c1, &c1);
	write(1, "\n", 1);
	printf("Number of characters printed with ft_printf above: %d\n", counter);


	return 0;
} 
