/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 11:08:58 by abureau           #+#    #+#             */
/*   Updated: 2016/03/30 14:40:11 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <unistd.h>
# include <wchar.h>
# define FIELD_MASK 0x1F

typedef unsigned long long u64;

typedef union		u_number
{
	double			d;
	int				i;
	char			*str;
	char			c;
	float			f;
	unsigned int	ui;
	unsigned char	uc;
	long			l;
	long int		li;
	long double		ld;
	long long		ll;
}					t_number;

typedef struct		s_flags
{
	unsigned int	b : 1;
	unsigned int	h : 1;
	unsigned int	n : 1;
	unsigned int	p : 1;
	unsigned int	z : 1;
	unsigned int	fmap : 5;
}					t_flags;

typedef struct		s_arglist
{
	t_number		number;
	t_flags			flags;
	unsigned short	blank;
	unsigned int	field;
	unsigned int	precision;
	struct s_arglist		*next;
}					t_arglist;

char				*ft_lltoabase(u64 value, unsigned int base, int signe);
char				*ft_itoh(unsigned int value);


#endif
