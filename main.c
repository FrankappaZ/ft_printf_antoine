/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:40:50 by abureau           #+#    #+#             */
/*   Updated: 2016/11/22 22:41:42 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/includes/libft.h"
#include <stdio.h>

int main(void)
{
//		ft_putstr("resr");
	printf(" - %.d - %.d\n", 42, 43);
	ft_printf(" - %.d - %.d\n", 42, 43);
	//	printf("coucou %#12.4o lol %% %n \n", 21, 42);
	return (0);
}
