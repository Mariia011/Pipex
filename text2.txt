NAME = pipex

GCC = gcc -Wall -Wextra -Werror

HELPERPATH = ./ft_printf/

HELPER = $(HELPERPATH)libftprintf.a

MAKE = make -C

MANDATORY = ./*.c

OBJS = $(MANDATORY:.c=.o)

all : $(NAME)

$(NAME) : $(HELPER) $(OBJS)
	$(GCC)  $(HELPER) $(OBJS) -o $@

$(HELPER) :
	$(MAKE) $(HELPERPATH)

$(OBJS) : $(MANDATORY)
	$(GCC) -c $(MANDATORY)

clean :
	$(MAKE)  $(HELPERPATH) clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE)  $(HELPERPATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
