#include "ft_printf.h"

ssize_t	print_p(void *addr)
{
	int		counter;
	uintptr_t	tmp;

	if (addr == NULL)
	{
		counter = write(1, "(nil)", 5);
		return (counter);
	}
	write(1, "0x", 2);
	counter = 2;
	tmp = (uintptr_t) addr;
	put_hex(tmp, &counter, 0);
	return (counter);
}
