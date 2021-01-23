# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blavonne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 18:43:11 by blavonne          #+#    #+#              #
#    Updated: 2019/09/18 20:20:05 by blavonne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = clean_two_dim.c\
		errors.c\
		ft_abs.c\
		ft_abs_ll.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isnumber.c\
		ft_isprint.c\
		ft_issign.c\
		ft_isspace.c\
		ft_itoa.c\
		ft_itoa_llu.c\
		ft_itoa_lu.c\
		ft_lstadd.c\
		ft_lstadd_back.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_min.c\
		ft_pow.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_reverse_bits.c\
		ft_sqrt.c\
		ft_str_tolower.c\
		ft_str_toupper.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_swap.c\
		ft_swap_bits.c\
		ft_tolower.c\
		ft_toupper.c\
		get_next_line.c\

OS = $(SRC:%.c=%.o)
FLAGS = -Wall -Werror -Wextra
INCLUDES = ./

all: $(NAME)
$(NAME): $(OS) $(INCLUDES)libft.h
	ar rcs $(NAME) $(OS)
%.o: %.c $(INCLUDES)libft.h
	gcc -c $< -o $@ $(FLAGS) -I $(INCLUDES)
clean:
	rm -rf $(OS)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re