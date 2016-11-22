#include "ft_printf.h"
#include "libft/includes/libft.h"

char	*glenmod3(t_pf *ptf, va_list val)
{
	char	c;

	c = ptf->len[0];
	if (c == 'h' && ptf->type == 'D')
		return (ft_uitoa(va_arg(val, int)));
	if (c == 'h' && (ptf->type == 'd' || ptf->type == 'i'))
		return (ft_itoa(va_arg(val, int)));
	if (c == 'h' && (ptf->type == 'o'))
		return (ft_ustoa_base((unsigned short)(va_arg(val, int)), 8));
	if (c == 'h' && (ptf->type == 'O'))
		return (ft_uitoa_base((unsigned int)(va_arg(val, int)), 8));
	if (c == 'h' && (ptf->type == 'u' || ptf->type == 'U'))
		return (ft_ustoa((unsigned short)(va_arg(val, long int))));
	if (c == 'h' && (ptf->type == 'x' || ptf->type == 'X'))
		return (ft_ustoa_base((unsigned short)(va_arg(val, int)), 16));
	return (NULL);
}

char		*glenmod2(t_pf *ptf, va_list val)
{
	char	c;

	c = ptf->len[0];
	if (c == 'j' && (ptf->type == 'D'))
		return (ft_imtoa(va_arg(val, intmax_t)));
	if (c == 'j' && (ptf->type == 'd' || ptf->type == 'i'))
		return (ft_imtoa(va_arg(val, intmax_t)));
	if (c == 'j' && (ptf->type == 'o' || ptf->type == 'O'))
		return (ft_uimtoa_base(va_arg(val, uintmax_t), 8));
	if (c == 'j' && (ptf->type == 'u' || ptf->type == 'U'))
		return (ft_uimtoa(va_arg(val, uintmax_t)));
	if (c == 'j' && (ptf->type == 'x' || ptf->type == 'X'))
		return (ft_uimtoa_base(va_arg(val, uintmax_t), 16));
	if (c == 'z' && (ptf->type == 'D'))
		return (ft_sttoa(va_arg(val, size_t)));
	if (c == 'z' && (ptf->type == 'd' || ptf->type == 'i'))
		return (ft_lltoa(va_arg(val, size_t)));
	if (c == 'z' && (ptf->type == 'o' || ptf->type == 'O'))
		return (ft_sttoa_base(va_arg(val, size_t), 8));
	if (c == 'z' && (ptf->type == 'u' || ptf->type == 'U'))
		return (ft_sttoa(va_arg(val, size_t)));
	if (c == 'z' && (ptf->type == 'x' || ptf->type == 'X'))
		return (ft_sttoa_base(va_arg(val, size_t), 16));
	return (glenmod3(ptf, val));
}

char		*glenmod1(t_pf *ptf, va_list val)
{
	if (ptf->type == 'd' || ptf->type == 'i')
		return (ft_ltoa(va_arg(val, long)));
	if (ptf->type == 'o' || ptf->type == 'O')
		return (ft_ultoa_base(va_arg(val, unsigned long), 8));
	if (ptf->type == 'u' || ptf->type == 'U')
		return (ft_ultoa(va_arg(val, unsigned long)));
	if (ptf->type == 'x' || ptf->type == 'X')
		return (ft_ultoa_base(va_arg(val, unsigned long), 16));
	if (ptf->type == 'c')
		return (ft_wctoa(va_arg(val, wchar_t)));
	if (ptf->type == 's')
		return (ft_wstoa(va_arg(val, wchar_t *)));
	if (ptf->type == 'D')
		return (ft_ltoa(va_arg(val, long int)));
	return (NULL);
}

char		*glenmod0(t_pf *ptf, va_list val)
{
	if (ft_strstr(ptf->len, "hh") && ptf->type == 'D')
		return (ft_uitoa((char)(va_arg(val, int))));
	if (ft_strstr(ptf->len, "hh") && (ptf->type == 'd' || ptf->type == 'i'))
		return (ft_itoa((char)(va_arg(val, int))));
	if (ft_strstr(ptf->len, "hh") && (ptf->type == 'o' || ptf->type == 'O'))
		return (ft_uctoa_base((unsigned char)(va_arg(val, int)), 8));
	if (ft_strstr(ptf->len, "hh") && (ptf->type == 'u' || ptf->type == 'U'))
		return (ft_uctoa((unsigned char)(va_arg(val, int))));
	if (ft_strstr(ptf->len, "hh") && (ptf->type == 'x' || ptf->type == 'X'))
		return (ft_uctoa_base((unsigned char)(va_arg(val, int)), 16));
	if (ft_strstr(ptf->len, "ll") && ptf->type == 'D')
		return (ft_lltoa(va_arg(val, long long)));
	if (ft_strstr(ptf->len, "ll") && (ptf->type == 'd' || ptf->type == 'i'))
		return (ft_lltoa(va_arg(val, long long)));
	if (ft_strstr(ptf->len, "ll") && (ptf->type == 'o' || ptf->type == 'O'))
		return (ft_ulltoa_base(va_arg(val, unsigned long long), 8));
	if (ft_strstr(ptf->len, "ll") && (ptf->type == 'u' || ptf->type == 'U'))
		return (ft_ulltoa(va_arg(val, unsigned long long)));
	if (ft_strstr(ptf->len, "ll") && (ptf->type == 'x' || ptf->type == 'X'))
		return (ft_ulltoa_base(va_arg(val, unsigned long long), 16));
	return (NULL);
}
