#include "ft_printf.h"

ssize_t put_nbr(uintptr_t addr, int *counter);

ssize_t print_p(void *p)
{
	int counter;

	counter = 0;
	uintptr_t tmp = (uintptr_t) p;
	return (put_nbr(tmp, &counter));
}

ssize_t put_nbr(uintptr_t addr, int *counter)
{
	char	c;
	int	tmp;

	if (addr > 9)
		put_nbr(addr / 10, counter);
	c = '0' + (addr % 10);
	tmp = write(1, &c, 1);
	if (temp < 0)
		
		return (-1);
}	
