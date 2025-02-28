NAME = push_swap

CC = gcc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror -I./includes -g

SRCS = src/push_swap.c\
		src/errors.c\
		src/parsing.c\
		src/node.c\
		src/head_bottom.c\
		src/sorting.c\
		src/commands.c\
		src/ft_split.c\
		src/utils.c\
		src/algos.c\
		src/algo_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re