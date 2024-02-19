########################################################################################################################
#                                                       VARIABLE                                                       #
########################################################################################################################
SRCS		:=	main.c\
				hook.c\
				draw.c\
				parsing.c\
				treat_value.c\
				creat_coord.c\
				utils.c\
				list_utils.c\
				draw_all.c\
				free.c

HEAD		:=	fdf.h

HEAD_D		:=	incs/

SRCS_D		:=	srcs/

OBJS_D		:=	.objs/

LIB_D		:= ./libft

OBJS		=	$(SRCS:%.c=$(OBJS_D)%.o)

HEAD_A		:=	$(addprefix $(HEAD_D), $(HEAD))

NAME		:=	fdf

LIB_A		:=	libft/libft.a


########################################################################################################################
#                                                        FLAGS                                                         #
########################################################################################################################
CC		:=	cc

RM		:=	rm -rf
# -fsanitize=address  -Wall -Wextra -Werror
CFLAGS	:=-I$(HEAD_D) -I$(LIB_D)

all			:	$(NAME)

$(NAME)		:	$(OBJS_D) $(OBJS) $(LIB_A)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lm -L./libft -lft -L./minilibx-linux -lmlx -lXext -lX11

$(LIB_A)	:
				make -C libft/

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD_A)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_D)	:
				mkdir -p $(OBJS_D)

leaks		:	all
				$(VALGRIND) ./$(NAME) $(MAPS)

clean		:
				$(RM) $(OBJS) $(OBJS_D)
				make -C libft/ clean

fclean		:	clean
				$(RM) $(NAME)
				make -C libft/ fclean

re			:	fclean all

.PHONY		:	all leaks clean fclean re