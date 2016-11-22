/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 11:08:58 by abureau           #+#    #+#             */
/*   Updated: 2016/11/22 21:37:20 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <unistd.h>
# include <wchar.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft/includes/libft.h"
# define FIELD_MASK 0x1F

typedef struct		s_pf
{
	int				dot;
	int				flag;
	int				prec;
	int				width;
	char			*len;
	char			*value;
	char			type;
}					t_pf;

int					ft_pow(int base, int power);
int					print_f(char *str, va_list val);
char				*makeoptions(t_pf *ptf);
int					ft_check(t_pf *ptf);
int					creat_str(t_pf *ptf, int flag, int dot);
char				*glenmod0(t_pf *ptf, va_list val);
char				*glenmod1(t_pf *ptf, va_list val);
char				*glenmod2(t_pf *ptf, va_list val);
char				*glenmod3(t_pf *ptf, va_list val);
char				*op_n(t_pf *ptf, int ret, va_list val);
char				*get_v(t_pf *ptf, int ret, va_list val);
int					get_p(char *str, int *ind, t_pf *ptf, va_list val);
int					get_w(char *str, int *ind, t_pf *ptf, va_list val);
int					is_comp(int flag, char tp, int dot);
void				upstr(char **str);
int					ck_value(t_pf *ptf);
int					check_type(char *str, int *i, t_pf *ptf);
int					get_type(char *str, int *i, t_pf *ptf);
char				*ft_ctoa(char c);
char				*g_f_len(char *str, int	*ind);
int					prev_check(char *str, int *ind, t_pf *ptf);
int					gcheck_width(char *str, int *ind);
int					free_ptf(t_pf *ptf);
int					is_check_format(char *str);
int					ft_printf(const char *format, ...);
int					get_flag(char *str, int	*i);
char				*ft_ulltoa(unsigned long long nbr);
char				*ft_ultoa(unsigned long nbr);
char				*ft_uitoa(unsigned int nbr);
char				*ft_ustoa(unsigned short nbr);
char				*ft_uctoa(unsigned char nbr);
char				*ft_uimtoa(uintmax_t nbr);
char				*ft_lltoa(long long nbr);
char				*ft_ltoa(long nbr);
char				*ft_lftoa(long double nbr);
char				*ft_imtoa(intmax_t nbr);
char				*ft_sttoa(size_t nbr);
char				*ft_ssttoa(ssize_t nbr);
char				*ft_ltoa_base(long nbr, int base);
char				*ft_sttoa_base(size_t nbr, int base);
char				*ft_uctoa_base(unsigned char nbr, int base);
char				*ft_uimtoa_base(uintmax_t nbr, int base);
char				*ft_itoa_base(int nbr, int base);
char				*ft_uitoa_base(unsigned int nbr, int base);
char				*ft_ustoa_base(unsigned short nbr, int base);
char				*ft_ultoa_base(unsigned long nbr, int base);
char				*ft_ulltoa_base(unsigned long long nbr, int base);
char				*ft_wstoa(wchar_t *wstr);
char				*ft_wctoa(wchar_t wc);
int					ft_mask4(char *str, int size, wchar_t wchar);
int					ft_mask1(char *str, int size, wchar_t wchar);
int					ft_mask2(char *str, int size, wchar_t wchar);
int					ft_mask3(char *str, int size, wchar_t wchar);

#endif
