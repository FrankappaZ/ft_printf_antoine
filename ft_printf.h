/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 11:08:58 by abureau           #+#    #+#             */
/*   Updated: 2016/03/31 17:52:36 by abureau          ###   ########.fr       */
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
	u64				ull;
}					t_number;

typedef struct		s_flags
{
	unsigned int	spac : 1;
	unsigned int	nega : 1;
	unsigned int	paus : 1;
	unsigned int	zero : 1;
	unsigned int	hash : 1;
}					t_flags;

typedef struct		s_modifier
{
	unsigned int	hh : 1;
	unsigned int	h : 1;
	unsigned int	l : 1;
	unsigned int	ll : 1;
	unsigned int	j : 1;
	unsigned int	z : 1;

}					t_modifier;

typedef struct		s_arglist
{
	t_number		number;
	unsigned int	field;
	unsigned int	precision;
	unsigned int	fmap : 5;
	unsigned int	modmap : 6;
	struct s_arglist		*next;
}					t_arglist;

typedef struct		s_desc
{
	t_arglist	*begin;
	va_list		*arglst;
}					t_desc;









char				*ft_lltoabase(u64 value, unsigned int base, int signe);
char				*ft_itoh(unsigned int value);
void	ft_printf(const char *format, ...);


#endif
