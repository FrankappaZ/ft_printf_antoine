/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:41:47 by abureau           #+#    #+#             */
/*   Updated: 2016/11/22 22:43:49 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/includes/libft.h"

int			ft_check(t_pf *ptf)
{
	if (ptf->type == 's' || ptf->type == 'S' || ptf->type == 'c')
		return (0);
	if (ptf->type == 'p' || ptf->type == 'n' || ptf->type == 'C')
		return (0);
	if (ptf->type == '%' || ptf->type == 'd')
		return (0);
	return (1);
}

static int	p_var(t_pf *ptf, char *str)
{
	int		size;
	int		i;
	char	c;

	i = 0;
	size = (ptf->type == 'c' && !str[0]) ? 1 : ft_strlen(str);
	size = (ptf->type == 'C' && !str[0]) ? 1 : size;
	if (ptf->type == 's' && ptf->dot == 2)
		ptf->dot = 0;
	if (ptf->type == 's' && ptf->dot && ptf->prec < size)
		size = ptf->prec;
	if (ptf->type == 'S' && ptf->dot && ptf->prec < size)
		size = ptf->prec;
	c = (ptf->flag & 16) ? '0' : ' ';
	if (ptf->flag & 1)
		write(1, str, size);
	while (size + i < ptf->width)
	{
		write(1, &c, 1);
		i++;
	}
	if (!(ptf->flag & 1))
		write(1, str, size);
	return (size + i);
}

int			creat_str(t_pf *ptf, int flag, int dot)
{
	char	*str;
	int		size;

	size = 0;
	(flag & 16 && flag & 1 && ptf->type == '%') ? ptf->flag -= 16 : 0;
	if (ptf->type == 'n' && free_ptf(ptf) < 0)
		return (0);
	if (ptf->type == '%' && ptf->dot && !(ptf->dot = 0))
		ptf->prec = 0;
	if (!ptf->dot && ptf->flag & 16)
	{
		ptf->prec = ptf->width;
		if (ptf->value[0] == '-' || ptf->flag & 2 || ptf->flag & 4)
			ptf->prec--;
	}
	if (dot && !ptf->prec && ptf->value[0] && ft_check(ptf))
		ptf->value[0] = 0;
	if (!(str = makeoptions(ptf)))
		return (-1);
	(ptf->type == 'X') ? upstr(&str) : 0;
	size = p_var(ptf, str);
	free(str);
	str = NULL;
	free_ptf(ptf);
	return (size);
}
