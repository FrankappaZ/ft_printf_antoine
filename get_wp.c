/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:41:11 by abureau           #+#    #+#             */
/*   Updated: 2016/11/22 21:49:41 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/includes/libft.h"

int			get_w(char *str, int *ind, t_pf *ptf, va_list val)
{
	int		j;
	char	*st;

	j = *ind;
	if (str[j] == '*' && ++(ind[0]))
	{
		if ((j = va_arg(val, int)) < 0)
		{
			ptf->flag += (ptf->flag & 1) ? 0 : 1;
			j = -j;
		}
		return (j);
	}
	while (ft_isdigit(str[j]))
		j++;
	if (j == *ind)
		return (0);
	st = ft_strsub(str, (unsigned int)*ind, j - *ind);
	if (!st)
		return (-1);
	*ind = j;
	j = ft_atoi(st);
	free(st);
	return ((j < 0) ? 0 : j);
}

int			get_p(char *str, int *ind, t_pf *ptf, va_list val)
{
	int		i;
	char	*st;

	i = 0;
	ptf->dot = 0;
	if (str[*ind] == '.' && ++(ptf->dot))
	{
		*ind += 1;
		if (str[*ind] == '*' && ++ind[0])
			return (((i = va_arg(val, int)) >= 0) ? i : ++(ptf->dot));
		while (ft_isdigit(str[*ind + i]))
			i++;
		if (i == 0 && (ptf->dot = 3))
			return (i);
		st = ft_strsub(str, (unsigned int)*ind, i);
		if (!st)
			return (-1);
		*ind += i;
		i = ft_atoi(st);
		free(st);
	}
	return ((i < 0) ? 0 : i);
}
