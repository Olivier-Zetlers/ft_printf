#include "ft_printf.h"

ssize_t print_s(const char* str)
{
	return (write(1, str, ft_strlen(str)));
}
