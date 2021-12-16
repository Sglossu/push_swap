NAME		=	push_swap
BNAME		=	checker
DIR			=	./srcs/
BDIR		=	./bsrcs/
HDIR		=	./include/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f

SRCS		=	$(DIR)push_swap.c					$(DIR)push.c					$(DIR)rotate.c \
				$(DIR)reverse_rotate.c				$(DIR)swap.c					$(DIR)utils.c \
				$(DIR)sorted.c						$(DIR)index.c					$(DIR)mini_sort.c \
				$(DIR)index_second.c				$(DIR)mini_sort_2.c				$(DIR)big_sort.c \
				$(DIR)move_counter.c				$(DIR)init_struct.c				$(DIR)moving_ba.c \
				$(DIR)minimum_push.c				$(DIR)double_rotate.c		

BSRCS		=	$(BDIR)checker.c					$(BDIR)checker_continue.c		$(BDIR)utils_c.c \
				$(BDIR)rotate_c.c					$(BDIR)reverse_rotate_c.c		$(BDIR)push_c.c \
				$(BDIR)swap_c.c


OBJS	= $(patsubst %.c,%.o, $(SRCS))
BOBJS	= $(patsubst %.c,%.o, $(BSRCS))

HEAD		= $(HDIR)push_swap.h
BHEAD		= $(HDIR)checker.h

LIB			= libft/libft.a
BLIB		= ./libft/libft.a

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEAD)
	$(MAKE) -C libft
	$(CC) -g $(CFLAGS) $(LIB) $(SRCS) -o $(NAME) 

bonus		:	$(BNAME)

$(BNAME)	:	$(BOBJS) $(BHEAD)
	$(MAKE) -C libft
	$(CC) -g $(CFLAGS) $(BLIB) $(BSRCS) -o $(BNAME) 

clean 		:
	$(MAKE) clean -C libft
	$(RM) $(OBJS) $(BOBJS)

fclean		:	clean
	$(MAKE) clean -C libft
	$(RM) $(NAME) $(BNAME)

re			:	fclean all

.PHONY		:	all clean fclean re bonus