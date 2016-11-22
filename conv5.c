/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:42:06 by abureau           #+#    #+#             */
/*   Updated: 2016/11/22 21:42:07 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

char	*ft_uctoa(unsigned char nbr)
{
	unsigned char		nb;
	int					i;
	char				*str;

	nb = nbr;
	i = 0;
	while (nb > 9 && ++i)
	{
		nb /= 10;
	}
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	while (i >= 0)
	{
		str[i--] = '0' + nbr % 10;
		nbr /= 10;
	}
	return (str);
}
