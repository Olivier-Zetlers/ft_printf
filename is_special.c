#include "ft_printf.h"

int is_special(char c)
{
	char *str;
	int i; 

	str = CONVERSION_SPECIFIERS; // Replaced by "cspdiuxX%"
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}
