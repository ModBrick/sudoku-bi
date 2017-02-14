##
## Makefile for my_printf in /home/jossel_a/rendu/PSU_2015_my_printf
## 
## Made by arthur josselin
## Login   <jossel_a@epitech.net>
## 
## Started on  Thu Nov  5 10:30:30 2015 arthur josselin
## Last update Thu Nov  5 10:30:30 2015 arthur josselin
##


CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -g
CFLAGS	+= -I./include

LDFLAGS	=

SRCS	= src/main.c \
	  src/set_function.c


OBJS	= $(SRCS:.c=.o)

NAME	= sudoki-bi

all: 	 $(NAMELIB) $(NAME)

$(NAME): $(OBJS)
	 @$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
