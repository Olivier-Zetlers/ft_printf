#include "ft_printf.h"

ssize_t	print_x(unsigned int num)
{
	int	counter;
	long	num_long;

	num_long = (long) num;
	counter = 0;
	put_hex((uintptr_t) num_long, &counter, 0);
	return (counter);
}

ssize_t	print_x_upper(unsigned int num)
{
	int	counter;
	long	num_long;

	num_long = (long) num;
	counter = 0;
	put_hex((uintptr_t) num_long, &counter, 1);
	return (counter);
}
