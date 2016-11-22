/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iscompat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:41:01 by abureau           #+#    #+#             */
/*   Updated: 2016/11/22 21:50:34 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_flag.h"
#include "ft_printf.h"

int	is_comp(int flag, char tp, int dot)
{
	if (flag & P_H && (tp == 'd' || tp == 'D' || tp == 'i' || tp == 'b'))
		return (-1);
	if (flag & P_H && (tp == 's' || tp == 'P' || tp == 'n' || tp == 'S'))
		return (-1);
	if ((tp == 'c' || tp == 'C')
			&& (flag & P_O || flag & P_P || flag & P_H || flag & P_S))
		return (-1);
	if ((tp == 'p') && (flag & P_O || flag & P_P || flag & P_S))
		return (-1);
	if ((tp == 'u' || tp == 'U') && (flag & P_H || flag & P_P || flag & P_S))
		return (-1);
	if ((tp == 'x' || tp == 'X') && (flag & P_P || flag & P_S))
		return (-1);
	if ((tp == 's' || tp == 'S') && (flag & P_P || flag & P_S || flag & P_O))
		return (-1);
	if ((tp == 'o' || tp == 'O' || tp == 'b') && (flag & P_P || flag & P_S))
		return (-1);
	if (flag & P_O && flag & P_M && tp == '%')
		flag = flag - (P_O);
	if (flag & P_O && flag & P_M && tp != '%')
		return (-1);
	if ((tp == 'S' || tp == 'c' || tp == 'p') && dot && dot != 3)
		return (-1);
	return ((flag & P_S && flag & P_P) ? -1 : 1);
}
