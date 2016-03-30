#include "ft_printf.h"
#include "libft/includes/libft.h"
#include <stdarg.h>

static void	strparser(const char *format, va_list args)
{
	
	
}

void	ft_printf(const char *format, ...)
{
	va_list args;
	
	if (format)
	{
		va_start(args, format);
		va_end(args);		
	}
	
}
