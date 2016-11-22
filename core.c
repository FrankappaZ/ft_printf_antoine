/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:41:52 by abureau           #+#    #+#             */
/*   Updated: 2016/11/22 22:37:53 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/includes/libft.h"

static char	*ft_strdup_n(const char *str)
{
	char	*snew;

	if (!str)
		return (ft_strdup_n("(null)"));
	snew = ft_strdup(str);
	return (snew);
}

static char	*add_adress(char *str)
{
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = ft_strnew(ft_strlen(str) + 2);
	if (!tmp)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	tmp[0] = '0';
	tmp[1] = 'x';
	ft_strcat(tmp, str);
	free(str);
	str = NULL;
	return (tmp);
}

static char	*get_v2(char t, va_list val)
{
	if (t == '%' || t == 'c')
		return (t == '%' ? ft_ctoa('%') : ft_ctoa(va_arg(val, int)));
	if (t == 'c')
		return (ft_ctoa(va_arg(val, int)));
	if (t == 'C')
		return (ft_wctoa(va_arg(val, wchar_t)));
	if (t == 'S')
		return (ft_wstoa(va_arg(val, wchar_t*)));
	if (t == 'p')
		return (add_adress(ft_ltoa_base(va_arg(val, wchar_t), 16)));
	return (NULL);
}

char		*get_v(t_pf *ptf, int ret, va_list val)
{
	if (ptf->type == 'n')
		return (op_n(ptf, ret, val));
	if (ptf->len[0] && ptf->len[1])
		return (glenmod0(ptf, val));
	if (ptf->len[0] == 'l')
		return (glenmod1(ptf, val));
	if (ptf->len[0])
		return (glenmod2(ptf, val));
	if (ptf->type == 's')
		return (ft_strdup_n(va_arg(val, char*)));
	if (ptf->type == 'd' || ptf->type == 'i')
		return (ft_itoa(va_arg(val, int)));
	if (ptf->type == 'D')
		return (ft_ltoa(va_arg(val, long int)));
	if (ptf->type == 'o')
		return (ft_uitoa_base(va_arg(val, unsigned int), 8));
	if (ptf->type == 'O')
		return (ft_ultoa_base(va_arg(val, unsigned long), 8));
	if (ptf->type == 'u')
		return (ft_uitoa(va_arg(val, unsigned long)));
	if (ptf->type == 'U')
		return (ft_ultoa(va_arg(val, unsigned long int)));
	if (ptf->type == 'x' || ptf->type == 'X')
		return (ft_uitoa_base(va_arg(val, unsigned int), 16));
	return (get_v2(ptf->type, val));
}
