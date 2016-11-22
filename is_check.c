/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:41:07 by abureau           #+#    #+#             */
/*   Updated: 2016/11/22 21:49:53 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include "./libft/includes/libft.h"

static int	flag_setter(char **str)
{
	int		i;
	t_pf	*ptf;

	ptf = (t_pf*)ft_memalloc(sizeof(t_pf));
	if (!ptf)
		return (-1);
	str[0]++;
	i = 0;
	ptf->flag = get_flag(*str, &i);
	ptf->width = gcheck_width(*str, &i);
	ptf->prec = prev_check(*str, &i, ptf);
	if (!(ptf->len = g_f_len(*str, &i)))
		return (free_ptf(ptf));
	if (check_type(*str, &i, ptf) < 0)
		return (free_ptf(ptf));
	if (ck_value(ptf) < 0)
		return (free_ptf(ptf));
	if (is_comp(ptf->flag, ptf->type, ptf->dot) < 0)
		return (free_ptf(ptf));
	*str = *str + i + 1;
	free_ptf(ptf);
	return (0);
}

int			is_check_format(char *str)
{
	int	ind;

	ind = 0;
	while (str[ind])
	{
		while (str[ind] && str[ind] != '%')
			ind++;
		if (ind)
			str += ind;
		if (str[ind] == '%' && flag_setter(&str) < 0)
			return (-1);
	}
	return (0);
}
