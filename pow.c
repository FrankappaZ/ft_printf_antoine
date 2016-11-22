/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:39:25 by abureau           #+#    #+#             */
/*   Updated: 2016/11/22 21:39:28 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_pow(int base, int power)
{
	int				res;

	res = 1;
	if (power == 0)
		return (1);
	if (base == 0)
		return (0);
	while (power > 1)
	{
		if (power % 2 != 0)
		{
			res *= base;
			power--;
		}
		while (power > 1 && power % 2 == 0)
		{
			base = base * base;
			power /= 2;
		}
	}
	res *= base;
	return (res);
}

unsigned int	ft_uipow(unsigned int base, int power)
{
	unsigned int	res;

	res = 1;
	if (power == 0)
		return (1);
	if (base == 0)
		return (0);
	while (power > 1)
	{
		if (power % 2 != 0)
		{
			res *= base;
			power--;
		}
		while (power > 1 && power % 2 == 0)
		{
			base = base * base;
			power /= 2;
		}
	}
	res *= base;
	return (res);
}
