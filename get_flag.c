#include "ft_printf.h"
#include "d_flag.h"
#include "libft/includes/libft.h"

char		*g_f_len(char *str, int	*ind)
{
	int	i;

	i = *ind;
	if (str[i] == 'h' && str[i + 1] == 'h')
	{
		*ind += 2;
		return (ft_strdup("hh"));
	}
	if (str[i] == 'l' && str[i + 1] == 'l')
	{
		*ind += 2;
		return (ft_strdup("ll"));
	}
	if (str[i] == 'l' || str[i] == 'h' || str[i] == 'j' || str[i] == 'z')
	{
		*ind += 1;
		return (ft_ctoa(str[i]));
	}
	return (ft_strnew(0));
}

int		prev_check(char *s, int *ind, t_pf *ptf)
{	
	int	i;

	i = 0;
	ptf->dot = 0;
	if (s[*ind] == '.' && ++(ptf->dot))
	{
		*ind += 1;
		if (s[*ind] == '*' && ++ind[0])
			return (1);
		while (ft_isdigit(s[*ind + i]))
			i++;
		if (i > 0)
			*ind += i;
		else if ((ptf->dot = 3))
			return (i);
	}
	return (i);
}

int		gcheck_width(char *s, int *ind)
{
	int	i;

	i = *ind;
	if (s[i] == '*')
	{
		*ind = *ind + 1;
		return (1);
	}
	while (ft_isdigit(s[i]))
		i++;
	if (i != *ind)
	{
		*ind = i;
		return (i);
	}
	return (0);
}

int		get_flag(char *s, int *i)
{
	int	option;

	option = 0;
	while (s[*i] == 45 || s[*i] == 43 || s[*i] == 35 || s[*i] == 32 || s[*i] == '0')
	{
		if (s[*i] == '-')
			option = option | P_M;
		if (s[*i] == '+')
			option = option | P_P;
		if (s[*i] == ' ')
			option = option | P_S;
		if (s[*i] == '#')
			option = option | P_H;
		if (s[*i] == '0')
			option = option | P_O;
		*i = *i + 1;		
	}
	return (option);
}
