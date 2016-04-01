/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:41:05 by abureau           #+#    #+#             */
/*   Updated: 2016/04/01 16:26:06 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/includes/libft.h"
#include "ft_printf.h"

void		get_param(char *c, t_desc *desc)
{
	int		type;
	int		i;
	char	*conversion;
	char	*flags;
	char	*modifier;

	conversion = ft_strdup("sSpdDioOuUxXcC\0");
	flags = ft_strdup("#-+ \0");
	modifier = ("hljz\0");

	while (conversion[i] != '\0')
		if (*c == conversion[i])

	while (flags[i] != '\0')
		if (*c == flags[i])

	while (modifier[i] != '\0')
		if (*c == modifier[i])

	if (ft_isdigit(*c))
		desc->;
}
