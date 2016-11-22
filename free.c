/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:41:30 by abureau           #+#    #+#             */
/*   Updated: 2016/11/22 21:41:32 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		free_ptf(t_pf *ptf)
{
	if (ptf)
	{
		if (ptf->len)
			free(ptf->len);
		if (ptf->value)
			free(ptf->value);
		free(ptf);
		ptf = NULL;
	}
	return (-1);
}
