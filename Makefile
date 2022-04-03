# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 14:21:19 by schene            #+#    #+#              #
#    Updated: 2022/04/03 21:39:09 by lemarabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_ping

CC =		gcc

SRCDIR =	srcs
OBJDIR =	.obj
INCLUDES =	-I include/ -I libft/include/

SRCS =		ft_ping.c utils.c

OBJS =		$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
DPDCS =		$(OBJS:.o=.d)
CFLAGS = 	-Wall -Wextra -Werror -fsanitize=address -g

LIB_NAME = 	libft
LIB_PATH = 	$(LIB_NAME)/$(LIB_NAME).a
LIB_FLAGS =	-L$(LIB_NAME) -lft

opti:
	@make -j all

all :
	@printf "[$(LIB_NAME)] " && make -C $(LIB_NAME)
	@make $(NAME)

-include $(DPDCS)

$(NAME) : $(OBJS) $(LIB_PATH)
	@printf "[$(NAME)] "
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) ${OBJS} $(LIB_PATH)
	@echo Compiled $(NAME) successfully !

$(OBJDIR)/%.o : $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR) :
	@mkdir -p .obj

clean :
	@rm -rf $(OBJDIR)
	@make clean -C $(LIB_NAME)

cleanlib :
	@make fclean -C $(LIB_NAME)

fclean : cleanlib clean
	@rm -rf $(NAME)

re :
	@make fclean
	@make opti