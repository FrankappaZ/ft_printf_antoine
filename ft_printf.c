#include "ft_printf.h"
#include "libft/includes/libft.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	int		return_value;
	va_list		val;
	char		*str;

	str = ft_strdup(format);
	if (!str)
		return (-1);
	if (is_check_format(str) < 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	str = NULL;
	va_start(val, format);
	return_value = print_f((char*)format, val);
	va_end(val);
	free(str);
	str = NULL;
	return (return_value);
}
