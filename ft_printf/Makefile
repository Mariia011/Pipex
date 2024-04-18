NAME = libftprintf.a
GCC = gcc -c -Wall -Wextra -Werror


MANDATORY = ./*.c
LIBFTPATH = ../libft/
TESTER = ./Tester_printf/
OBJS = $(MANDATORY:.c=.o)

NAME = libftprintf.a
MANDATORY = ./*.c
LIBFT_OBJS = $(LIBFTPATH)*.o
LIBFT_C = $(LIBFTPATH)*.c
OBJS = $(MANDATORY:.c=.o)

all: $(NAME)

$(NAME) : $(LIBFT_OBJS) $(OBJS)
	ar -rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

$(OBJS) : $(MANDATORY)
	$(GCC) $(MANDATORY)

$(LIBFT_OBJS) :
	make -C $(LIBFTPATH) all

clean :
	make -C $(LIBFTPATH) clean
	rm -f $(OBJS)
fclean : clean
	make -C $(LIBFTPATH) fclean
	rm -f $(NAME)


re: fclean all
