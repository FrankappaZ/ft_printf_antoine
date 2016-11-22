#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 19:21:45 by abureau           #+#    #+#              #
#    Updated: 2016/11/22 19:21:45 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = ./conv6.c \
	./iscompat.c \
	./conv.c \
	./libft/includes/ft_memcpy.c \
	./libft/includes/ft_tolower.c \
	./libft/includes/ft_strcmp.c \
	./libft/includes/ft_strtrimchar.c \
	./libft/includes/ft_countermul.c \
	./libft/includes/ft_strnew.c \
	./libft/includes/ft_initfourvar.c \
	./libft/includes/ft_putchar.c \
	./libft/includes/ft_counterdiv.c \
	./libft/includes/ft_strstr.c \
	./libft/includes/ft_itoa.c \
	./libft/includes/ft_inctwovar.c \
	./libft/includes/ft_counterpow.c \
	./libft/includes/ft_putendl.c \
	./libft/includes/ft_putnbrnl.c \
	./libft/includes/ft_putnbr.c \
	./libft/includes/ft_strdel.c \
	./libft/includes/ft_striteri.c \
	./libft/includes/ft_memchr.c \
	./libft/includes/ft_counteradd.c \
	./libft/includes/ft_pow.c \
	./libft/includes/ft_isalnum.c \
	./libft/includes/ft_lstdelone.c \
	./libft/includes/ft_strsub.c \
	./libft/includes/ft_incthreevar.c \
	./libft/includes/ft_strncpy.c \
	./libft/includes/ft_countermodul.c \
	./libft/includes/ft_strequ.c \
	./libft/includes/ft_strchr.c \
	./libft/includes/ft_putstr_fd.c \
	./libft/includes/ft_strmapi.c \
	./libft/includes/ft_memdel.c \
	./libft/includes/ft_lstmap.c \
	./libft/includes/ft_memcmp.c \
	./libft/includes/ft_strncmp.c \
	./libft/includes/ft_lstiter.c \
	./libft/includes/ft_counterrecap.c \
	./libft/includes/ft_putchar_fd.c \
	./libft/includes/ft_strtrim.c \
	./libft/includes/ft_strlcat.c \
	./libft/includes/ft_square.c \
	./libft/includes/ft_incdecvar.c \
	./libft/includes/ft_atoi.c \
	./libft/includes/ft_isascii.c \
	./libft/includes/ft_lstadd.c \
	./libft/includes/ft_memmove.c \
	./libft/includes/ft_putendl_fd.c \
	./libft/includes/ft_striter.c \
	./libft/includes/ft_isprint.c \
	./libft/includes/ft_memalloc.c \
	./libft/includes/ft_counterinitfunc.c \
	./libft/includes/ft_putstr.c \
	./libft/includes/ft_putnbr_fd.c \
	./libft/includes/ft_strnequ.c \
	./libft/includes/ft_isdigit.c \
	./libft/includes/ft_putstrnb.c \
	./libft/includes/ft_countereq.c \
	./libft/includes/ft_countertab.c \
	./libft/includes/ft_strjoin.c \
	./libft/includes/ft_strsplit.c \
	./libft/includes/ft_strnstr.c \
	./libft/includes/ft_counterfree.c \
	./libft/includes/ft_toupper.c \
	./libft/includes/ft_isalpha.c \
	./libft/includes/ft_strcpy.c \
	./libft/includes/ft_memccpy.c \
	./libft/includes/ft_inittwovar.c \
	./libft/includes/ft_bzero.c \
	./libft/includes/ft_lstdel.c \
	./libft/includes/ft_lstnew.c \
	./libft/includes/ft_strclr.c \
	./libft/includes/ft_initthreevar.c \
	./libft/includes/ft_counterset.c \
	./libft/includes/ft_strlen.c \
	./libft/includes/ft_counterinit.c \
	./libft/includes/ft_strncat.c \
	./libft/includes/ft_incfourvar.c \
	./libft/includes/ft_memset.c \
	./libft/includes/ft_strdup.c \
	./libft/includes/ft_countermod.c \
	./libft/includes/ft_strrchr.c \
	./libft/includes/ft_strcat.c \
	./libft/includes/ft_strmap.c \
	./is_check.c \
	./pow.c \
	./ft_printf.c \
	./makeoptions.c \
	./core.c \
	./create_str.c \
	./lenmod.c \
	./wchar.c \
	./conv3.c \
	./upstr.c \
	./get_wp.c \
	./conv5.c \
	./checktype.c \
	./wstoa.c \
	./free.c \
	./conv2.c \
	./get_flag.c \
	./masks.c \
	./conv4.c \
	./ctoa.c \
	./print_f.c \
	./op_n.c \
	./ck_value.c

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
