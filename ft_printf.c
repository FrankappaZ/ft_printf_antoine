#include "ft_printf.h"
#include "libft/includes/libft.h"
#include <stdarg.h>

static void	getvalue(const char *str, t_desc *desc)
{
	int	i;

	i = 0;
	
}

static int	strparser(const char *format, t_desc *desc)
{
	int	i;
	int	nbr_arg;

	i = 0;
	nbr_arg = 0;

	while (format[i])
	{
		if (format[i] == '%')
			(format[i + 1] == '%') ? i++ : getvalue(&format[i], desc);
		i++;
	}
	return (nbr_arg);
}
/*
static int	strcount(const char *format)
{
	int	i;
	int	nbr_arg;

	i = 0;
	nbr_arg = 0;

	while (format[i])
	{
		if (format[i] == '%')
			(format[i + 1] == '%') ? i++ : nbr_arg++;
		i++;
	}
	return (nbr_arg);
}
*/

void	ft_printf(const char *format, ...)
{
	va_list		args;
	t_desc		desc;

	ft_bzero(&desc, sizeof(t_desc));
	desc.arglst = &args;
	if (format)
	{
		va_start(*desc.arglst, format);
		strparser(format, &desc);
	}

}
