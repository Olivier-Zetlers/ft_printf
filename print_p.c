#include "ft_printf.h"

void put_addr(uintptr_t addr, int *counter);

ssize_t print_p(void *addr)
{
	int counter;

	// STEP 1: print prefix 0x
	write(1, "0x", 2);

	// STEP 2: print address in hex
	counter = 2; // Due to step 1
	uintptr_t tmp = (uintptr_t) addr;
	put_addr(tmp, &counter);
	return (counter);
}

void put_addr(uintptr_t addr, int *counter)
{
	char	c;
	char	*hex = "0123456789abcdef";
	int	tmp;

	if ((addr > 15) && (*counter >= 0))
		put_addr(addr / 16, counter);
	else if (*counter < 0)
		return;
	c = hex[addr % 16];
	tmp = write(1, &c, 1);
	if (tmp >= 0)
		*counter +=tmp;
	else
	{
		*counter = -1;
		return;
	}
}	
