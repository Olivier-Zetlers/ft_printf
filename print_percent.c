#include "ft_printf.h"

ssize_t	print_percent(void)
{
	int	counter;

	counter = write(1, "%", 1);
	return (counter);
}
