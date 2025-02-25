#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int	check;
	size_t	i;
	size_t	counter;
	va_list	args; // Liste d'arguments

	va_start(args, format);
	check = 0; // Inutile ?
	i = 0;
	counter = 0;
	while (format[i])
	{
		// CAS 1: Le caractère est un '%'
		if (format[i] == '%')
		{
			// SOUS-CAS 1a: Le % est suivi d'un caractère spécial => imprimer variable formatée et incrémenter i de 2
			if (is_special(format[++i])) // Si char suivant est spécial, alors imprimer arg suivant formaté
			{
				check = print_special(format[i], &args);
				if (check >= 0)
					counter += check;
				else
					return (PRINT_SPECIAL_FAILED); 
				i++;
			}
			// SOUS-CAS 1b : le % n'est pas suivi d'un caractère spécial => imprimer % et incrément i de 1 (fait ds 'if' CAS 1a) 
			else	
				write(1, "%", 1); // A PRIORI,  CAS INUTILE CAR GNU printf non compilable avec un % isolé
		}
		// CAS 2 : Le caractère n'est pas un '%' -> imprimer caractèere et incrémenter i (fait ds 'if' CAS 1)
		else
			counter += write(1, &format[i++], 1);
	}			
	va_end(args);	
	return (counter);
}	
