# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 16:44:59 by claferna          #+#    #+#              #
#    Updated: 2024/03/25 16:54:02 by claferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get_next_line.a

CFLAGS	=	-Wall -Wextra -Werror

LIB		=	ar -rcs

RM		=	rm -f

SRC		=	get_next_line.c	get_next_line_utils.c

OBJS	=	$(SRC:.c=.o)

all		:	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

.c.o	:	
			cc $(FLAGS) -c $<c -o $(<:.c=.o)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

.PHONY	:	all clean fclean re

re		:	fclean all
