/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:40:30 by abureau           #+#    #+#             */
/*   Updated: 2016/11/22 21:40:32 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_printf.h"

char		*op_n(t_pf *print, int ret, va_list ap)
{
	char	*str;
	int		passed;

	passed = 0;
	str = ft_strnew(0);
	if (!str)
		return (NULL);
	if (!print->len[0] && ++passed)
		*(va_arg(ap, int*)) = ret;
	else if (print->len[1] == 'l' && print->len[0] == 'l' && ++passed)
		*(va_arg(ap, long long*)) = ret;
	else if (print->len[1] == 'h' && print->len[0] == 'h' && ++passed)
		*(va_arg(ap, signed char*)) = ret;
	else if (print->len[0] == 'l' && ++passed)
		*(va_arg(ap, long*)) = ret;
	else if (print->len[0] == 'j' && ++passed)
		*(va_arg(ap, intmax_t*)) = ret;
	else if (print->len[0] == 'h' && ++passed)
		*(va_arg(ap, short*)) = ret;
	else if (print->len[0] == 'z' && ++passed)
		*(va_arg(ap, short*)) = ret;
	return ((passed == 0) ? NULL : str);
}
