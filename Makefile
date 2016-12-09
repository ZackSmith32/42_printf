# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/22 16:32:25 by zsmith            #+#    #+#              #
#    Updated: 2016/12/08 14:41:54 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
FLAGS	=	-c -Wall -Wextra -Werror
CFILES	=	ft_printf.c			\
			funx__flag.c		\
			funx__help.c		\
			funx__list.c		\
			funx__pop.c			\
			funx__pop2.c		\
			funx__wide.c		\
			funx_d.c			\
			funx_o.c			\
			funx_pi.c			\
			funx_s.c			\
			funx_u.c			\
			funx_x.c			\
			glob.c				\

SRCDIR  =	srcs/
HDIR	=	includes/
OFILES	=	$(CFILES:.c=.o)

.PHONY: all $(NAME) main complib clean flcean re

all: $(NAME)

$(NAME): comp_printf
	@ libtool -static -o $@ libfunc.a ./includes/libft.a

comp_printf:
	@ gcc $(FLAGS) $(addprefix $(SRCDIR),$(CFILES))
	@ ar rc libfunc.a $(OFILES)

clean:
	@ /bin/rm -f $(OFILES)

fclean: clean
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f libfunc.a

re: fclean all