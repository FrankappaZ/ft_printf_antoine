
#ifndef _FT_PRINTF_H
#define _FT_PRINTF_H

#include <unistd.h>
#include <wchar.h>

typedef union u_number
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

}t_number;

typedef struct s_arglist
{
	t_number number;
	char *flags;
	s_arglist *next;
}t_arglist;

char *ft_itoh(unsigned int value);


#endif
