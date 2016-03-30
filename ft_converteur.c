/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converteur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 10:22:20 by abureau           #+#    #+#             */
/*   Updated: 2016/03/30 14:20:26 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include "libft/includes/libft.h"

static int	lenght(unsigned int value)
{
	int i;

	i = 0;
	if (value == 0)
	i++;
	while (value != 0)
	{
		value /= 16;
		i++;
	}
	return (i);
}

static char	*strjoin(char *signe, char *str)
{
	char	*result;
	int		i;

	i = ft_strlen(str) + ft_strlen(signe);
	result = ft_strnew(i);
	if (!result)
		return (NULL);
	return (result);
}

static char	*valtostr(unsigned long value, unsigned int base)
{
	int len;
	char *str;

	len = lenght(value);
	str = ft_strnew(len + 1);
	if (!str)
		return (NULL);
	while (len > 0)
	{
		len --;
		str[len] = (value % base) > 9 ?
			(value % base) - 10 + 'a' : (value % base) + '0';
		value = value / base;
	}
	return (str);
}

char	*ft_converteur()
{
	char	*result;

	return (result);
}
