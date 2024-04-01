NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -c

MANDATORY	= *.c

OBJS = $(MANDATORY:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS) : $(MANDATORY)
	$(CC) $(CFLAGS) $(MANDATORY)

bonus : $(NAME) $(BONUS_OBJS)

	ar -rcs $(NAME) $(BONUS_OBJS)


clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY :  all clean fclean re bonus
