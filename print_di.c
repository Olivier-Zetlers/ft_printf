#include "ft_printf.h"

void put_nbr(long num, int *counter);

ssize_t print_di(int num)
{
	int counter;

	counter = 0;
	put_nbr((long) num, &counter);
	return (counter);
}

void put_nbr(long num, int *counter)
{
	char	c;
	ssize_t	temp;

	if (num < 0)
	{
		*counter += write(1, "-", 1);
		num *= -1;
	}
	if ((num > 9) && (*counter >= 0))
		put_nbr(num/10, counter);
	else if (*counter < 0)
		return;
	c = '0' + (num % 10);
	temp = write(1, &c, 1);
	if (temp >= 0)
		*counter += temp;
	else
	{
		*counter = -1;
		return;
	}
}
	
