# variable declaration*/

NAME	=	libft.a

INC		=	libft.h
SRC		=	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c

OBJ_DIR	=	.objs

FLAGS	=	-Wall -Wextra -Werror -I$(LIB_D)

OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIB_D		:= ./ft_printf

LIB_A		:=	ft_printf/libftprintf.a


all	:	$(NAME)

$(NAME) : $(OBJ)
	$(AR) rcs libft_temp.a $^
	$(AR) rcT libft.a libft_temp.a ft_printf/libftprintf.a

$(OBJ_DIR)/%.o : %.c $(INC) $(LIB_A)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

$(LIB_A)	:
	make -C ft_printf/

clean :
	$(RM) -rf $(OBJ)
	$(RM) -r $(OBJ_DIR)
	make -C ft_printf/ clean

fclean :
	$(MAKE) clean
	$(RM) $(NAME)
	$(RM) libft_temp.a
	make -C ft_printf/ fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re