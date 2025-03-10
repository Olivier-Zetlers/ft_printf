#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h> // For size_t
# include <stdint.h> // For uintptr_t
# include <unistd.h> // For write() and ssize_t
# include "../libft/inc/libft.h"
# define PRINT_SPECIAL_FAILED -1 // ERROR CODE
# define CONVERSION_SPECIFIERS "cspdiuxX%" // conversion specifiers handledi

int		ft_printf(const char *format, ...);
int		is_special(char c);
ssize_t		print_c(char c);
ssize_t		print_di(int num);
ssize_t		print_p(void *addr);
ssize_t		print_s(const char *str);
ssize_t		print_u(unsigned int num);
ssize_t		print_x_upper(unsigned int num);
ssize_t		print_x(unsigned int num);
ssize_t		print_percent(void);
size_t		print_special(char c, va_list *args);
void		put_hex(uintptr_t val, int *counter, int flag);
#endif
