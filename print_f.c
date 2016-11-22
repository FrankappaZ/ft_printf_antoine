/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:38:20 by abureau           #+#    #+#             */
/*   Updated: 2016/11/22 21:39:02 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/includes/libft.h"

static int		get_var(char **str, int ret, va_list val)
{
	int		i;
	t_pf	*ptf;

	ptf = (t_pf*)ft_memalloc(sizeof(t_pf));
	if (!ptf)
		return (-1);
	i = 0;
	ptf->flag = get_flag(*str, &i);
	if ((ptf->width = get_w(*str, &i, ptf, val)) < 0)
		return (free_ptf(ptf));
	if ((ptf->prec = get_p(*str, &i, ptf, val)) < 0)
		return (free_ptf(ptf));
	if (!(ptf->len = g_f_len(*str, &i)))
		return (free_ptf(ptf));
	if (get_type(*str, &i, ptf) < 0)
		return (free_ptf(ptf));
	if (!(ptf->value = get_v(ptf, ret, val)))
		return (free_ptf(ptf));
	str[0] += i + 1;
	return (creat_str(ptf, ptf->flag, ptf->dot));
}

static int		printvar(char **str, int ret, va_list val)
{
	str[0]++;
	if (**str == '%')
	{
		write(1, *str, 1);
		str[0]++;
		return (1);
	}
	return (get_var(str, ret, val));
}

int				print_f(char *str, va_list val)
{
	int	j;
	int	ret;

	ft_inittwovar(&i, &j, &ret);
	while (*str)
	{
		j = 0;
		while (str[j] && str[j] != '%')
			j++;
		if (j)
		{
			write(1, str, j);
			ret = ret + j;
			str = str + j;
			j = 0;
		}
		if (*str == '%' && (j = printvar(&str, ret, val)) < 0)
			return (-1);
		else if (j)
			ret += j;
	}
	return (ret);
}
