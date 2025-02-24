#include "ft_printf.h"

ssize_t print_c(char c)
{
	return (write(1, &c, 1));
}
