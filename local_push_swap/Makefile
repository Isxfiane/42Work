########################################################################################################################
#                                                       VARIABLE                                                       #
########################################################################################################################
SRCS		:=	main.c\
				list_func.c\
				list_base_fun.c\
				fill_list.c\
				sort_function.c\
				sort_algo.c\
				algo_for_small.c

HEAD		:=	test.h

HEAD_D		:=	./incs/

SRCS_D		:=	srcs/

OBJS_D		:=	.objs/

LIB_D		:= ./libft

OBJS		=	$(SRCS:%.c=$(OBJS_D)%.o)

HEAD_A		:=	$(addprefix $(HEAD_D), $(HEAD))

NAME		:=	push_swap

LIB_A		:=	libft/libft.a


########################################################################################################################
#                                                        FLAGS                                                         #
########################################################################################################################
CC		:=	cc

RM		:=	rm -rf

CFLAGS	:=	-Wall -Wextra -Werror -I$(HEAD_D) -I$(LIB_D)

all			:	$(NAME)

$(NAME)		:	$(OBJS_D) $(OBJS) $(LIB_A)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft

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