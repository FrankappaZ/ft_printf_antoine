/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:42:02 by abureau           #+#    #+#             */
/*   Updated: 2016/11/22 21:42:03 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

char	*ft_itoa_base(int nbr, int base)
{
	int					nb;
	char				*str;
	char				*conv;
	int					i;

	i = (nbr > 0) ? 0 : 1;
	nb = nbr;
	conv = "0123456789abcdefg";
	if (base == 10)
		return (ft_itoa(nbr));
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	i--;
	while (i >= 0)
	{
		str[i--] = conv[nbr % base];
		nbr /= base;
	}
	return (str);
}

char	*ft_uitoa_base(unsigned int nbr, int base)
{
	unsigned int		nb;
	char				*str;
	char				*conv;
	int					i;

	i = (nbr > 0) ? 0 : 1;
	nb = nbr;
	conv = "0123456789abcdefg";
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	i--;
	while (i >= 0)
	{
		str[i--] = conv[nbr % base];
		nbr /= base;
	}
	return (str);
}

char	*ft_ustoa_base(unsigned short nbr, int base)
{
	unsigned short		nb;
	char				*str;
	char				*conv;
	int					i;

	i = (nbr > 0) ? 0 : 1;
	nb = nbr;
	conv = "0123456789abcdefg";
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	i--;
	while (i >= 0)
	{
		str[i--] = conv[nbr % base];
		nbr /= base;
	}
	return (str);
}

char	*ft_ultoa_base(unsigned long nbr, int base)
{
	unsigned long		nb;
	char				*str;
	char				*conv;
	int					i;

	i = (nbr > 0) ? 0 : 1;
	nb = nbr;
	conv = "0123456789abcdefg";
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	i--;
	while (i >= 0)
	{
		str[i--] = conv[nbr % base];
		nbr /= base;
	}
	return (str);
}

char	*ft_ulltoa_base(unsigned long long nbr, int base)
{
	unsigned long long	nb;
	char				*str;
	char				*conv;
	int					i;

	i = (nbr > 0) ? 0 : 1;
	nb = nbr;
	conv = "0123456789abcdefg";
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	i--;
	while (i >= 0)
	{
		str[i--] = conv[nbr % base];
		nbr /= base;
	}
	return (str);
}
