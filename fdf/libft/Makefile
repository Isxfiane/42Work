# variable declaration*/

NAME	=	libft.a

INC		=	libft.h
SRC		=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_get_size.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_printf.c \
			ft_printf_utils.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putnbr_hexa.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_str2cpy.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strfind.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c\
			ft_atoi_base.c\
			ft_lower_string.c


OBJ_DIR	=	.objs

FLAGS	=	-Wall -Wextra -Werror -I .

OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


all	:	$(NAME)

$(NAME) : $(OBJ)
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o : %.c $(INC)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) -rf $(OBJ)
	$(RM) -r $(OBJ_DIR)

fclean :
	$(MAKE) clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re