#include "ft_printf.h"

// N'y a-t-il pas une manière plus élégante de traiter les différents cas ?
size_t print_special(char c, va_list *args)
{
	// cspdiuxX%
	if (c == 'c')
		return (print_c((char) va_arg(*args, int))); // int car default argument promotion
	else if (c == 's')
		return (print_s(va_arg(*args, char *)));
	else if (c == 'p')
		return (print_p( (void *) va_arg(*args, void *)));
	else if ((c == 'd') || (c == 'i'))
		return (print_di(va_arg(*args, int)));
	else if (c == 'u')
		return (1 );
	else if (c == 'x')
		return (1 );
	else if (c == 'X')
		return (1 ) ;
	else 
		return (-1);
}
