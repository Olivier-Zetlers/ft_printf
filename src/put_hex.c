#include "ft_printf.h"

void	put_hex(uintptr_t val, int *counter, int flag)
{
	char		c;
	char		*hex_lower;
	char		*hex_upper;
	int		tmp;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	if ((val > 15) && (*counter >= 0))
		put_hex(val / 16, counter, flag);
	if (*counter < 0)
		return ;
	if (flag == 0)
		c = hex_lower[val % 16];
	else
		c = hex_upper[val % 16];
	tmp = write(1, &c, 1);
	if (tmp >= 0)
		*counter += tmp;
	else
	{
		*counter = -1;
		return ;
	}
}
