#include "ft_printf.h"


ssize_t	handle_special(const char *format, size_t *i, va_list *args);

int	ft_printf(const char *format, ...)
{
	int		check;
	size_t		i;
	size_t		counter;
	va_list		args;

	va_start(args, format);
	i = 0;
	counter = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			check = handle_special(format, &i, &args);
			if (check < 0)
				return (PRINT_SPECIAL_FAILED);
			counter += check;
		}
		else
			counter += write(1, &format[i++], 1);
	}
	va_end(args);
	return (counter);
}

ssize_t	handle_special(const char *format, size_t *i, va_list *args)
{
	if (is_special(format[++(*i)]))
		return (print_special(format[(*i)++], args));
	else
	{
		(*i)++;
		return (write(1, "%", 1));
	}
}		
