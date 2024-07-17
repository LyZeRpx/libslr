##
## EPITECH PROJECT, 2024
## libslr
## File description:
## Makefile
##

CC ?= gcc

AR ?= ar

RM = rm

SRC 	=	src/file.c			\

NAME = libslr.a

VPATH = ./headers

CPPFLAGS = -iquote $(VPATH) -Wall -Wextra

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(AR) -rc $(NAME) $(OBJ)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

test:
	$(CC) main.c -o slr $(CPPFLAGS) -L. -lslr

debug: CFLAGS += -g3
debug: re

.PHONY: all clean fclean re debug test\
