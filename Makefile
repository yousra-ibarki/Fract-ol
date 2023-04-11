# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 21:32:43 by yoibarki          #+#    #+#              #
#    Updated: 2023/04/09 16:53:55 by yoibarki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = 	main.c \
		ft_mandelbrot.c \
		ft_julia.c \
		ft_tricorn.c \
		ft_coloring.c \
		ft_add.c \
		ft_handel_keys.c 

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):$(OBJS) fractol.h
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(MLX)

clean:
	@rm -f $(OBJS)

fclean:clean
	@rm -f $(NAME)

re: fclean all

.phony: re clean fclean all