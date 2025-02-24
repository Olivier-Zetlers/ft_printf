#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stddef.h> // For size_t
#include <stdint.h> // For uintptr_t
#include <stdio.h> // For printf() -----------------> DON'T FORGET TO REMOVE
#include <unistd.h> // For write() and ssize_t
#include "libft/libft.h"

// ERROR CODES
#define PRINT_SPECIAL_FAILED -1


#define CONVERSION_SPECIFIERS "cspdiuxX%"

int ft_printf(const char *format, ...);
int is_special(char c);
ssize_t print_c(char c);
ssize_t print_p(void *p);
ssize_t print_s(const char* str);
size_t print_special(char c, va_list *args);


#endif
