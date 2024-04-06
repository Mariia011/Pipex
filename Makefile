NAME = pipex

GCC = gcc #-Wall -Wextra -Werror

LIBFT = ./libft/libft.a

MAKE = make -C

MANDATORY = ./*.c

OBJS = $(MANDATORY:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(GCC) $(LIBFT) $(OBJS) -o $@

$(LIBFT) :
	$(MAKE) ./libft

$(OBJS) : $(MANDATORY)
	$(GCC) -c $(MANDATORY)

clean :
	rm -f $(OBJS)

fclean :
	$(MAKE)  ./libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
