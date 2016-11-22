/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_value.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:42:33 by abureau           #+#    #+#             */
/*   Updated: 2016/11/22 21:44:42 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include "libft/includes/libft.h"

static int	lenmod3(t_pf *prnt)
{
	if (prnt->type == 'i')
		return (1);
	if (prnt->type == 'd' || prnt->type == 'D')
		return (1);
	if (prnt->type == 'o' || prnt->type == 'O')
		return (1);
	if (prnt->type == 'u' || prnt->type == 'U')
		return (1);
	if (prnt->type == 'x' || prnt->type == 'X')
		return (1);
	if (prnt->type == 'n')
		return (1);
	return (-1);
}

static int	lenmod2(t_pf *prnt)
{
	char	c;

	c = prnt->len[0];
	if (c == 'j' && (prnt->type == 'i' || prnt->type == 'n'))
		return (1);
	if (c == 'j' && (prnt->type == 'd' || prnt->type == 'D'))
		return (1);
	if (c == 'j' && (prnt->type == 'o' || prnt->type == 'O'))
		return (1);
	if (c == 'j' && (prnt->type == 'u' || prnt->type == 'U'))
		return (1);
	if (c == 'j' && (prnt->type == 'x' || prnt->type == 'X'))
		return (1);
	if (c == 'z' && (prnt->type == 'i' || prnt->type == 'n'))
		return (1);
	if (c == 'z' && (prnt->type == 'd' || prnt->type == 'D'))
		return (1);
	if (c == 'z' && (prnt->type == 'o' || prnt->type == 'O'))
		return (1);
	if (c == 'z' && (prnt->type == 'u' || prnt->type == 'U'))
		return (1);
	if (c == 'z' && (prnt->type == 'x' || prnt->type == 'X'))
		return (1);
	return (-1);
}

static int	lenmod1(t_pf *prnt)
{
	if (prnt->type == 'd' || prnt->type == 'i')
		return (1);
	if (prnt->type == 'o' || prnt->type == 'O')
		return (1);
	if (prnt->type == 'u' || prnt->type == 'U')
		return (1);
	if (prnt->type == 'x' || prnt->type == 'X')
		return (1);
	if (prnt->type == 'n' || prnt->type == 'D')
		return (1);
	if (prnt->type == 'c')
		return (1);
	if (prnt->type == 's')
		return (1);
	return (-1);
}

static int	lenmod0(t_pf *prnt)
{
	if (ft_strstr(prnt->len, "hh") && (prnt->type == 'd' || prnt->type == 'D'))
		return (1);
	if (ft_strstr(prnt->len, "hh") && (prnt->type == 'o' || prnt->type == 'O'))
		return (1);
	if (ft_strstr(prnt->len, "hh") && (prnt->type == 'u' || prnt->type == 'U'))
		return (1);
	if (ft_strstr(prnt->len, "hh") && (prnt->type == 'x' || prnt->type == 'X'))
		return (1);
	if (ft_strstr(prnt->len, "hh") && (prnt->type == 'n' || prnt->type == 'i'))
		return (1);
	if (ft_strstr(prnt->len, "ll") && (prnt->type == 'd' || prnt->type == 'D'))
		return (1);
	if (ft_strstr(prnt->len, "ll") && (prnt->type == 'o' || prnt->type == 'O'))
		return (1);
	if (ft_strstr(prnt->len, "ll") && (prnt->type == 'u' || prnt->type == 'U'))
		return (1);
	if (ft_strstr(prnt->len, "ll") && (prnt->type == 'x' || prnt->type == 'X'))
		return (1);
	if (ft_strstr(prnt->len, "ll") && (prnt->type == 'n' || prnt->type == 'i'))
		return (1);
	return (-1);
}

int			ck_value(t_pf *ptf)
{
	if (ptf->len[0] && ptf->len[1])
		return (lenmod0(ptf));
	if (ptf->len[0] == 'l')
		return (lenmod1(ptf));
	if (ptf->len[0] == 'j' || ptf->len[0] == 'z')
		return (lenmod2(ptf));
	if (ptf->len[0] == 'h')
		return (lenmod3(ptf));
	return (1);
}
