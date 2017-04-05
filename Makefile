##
## Makefile for emacs in /home/kevin.ferchaud
## 
## Made by ferchaud kevin
## Login   <kevin.ferchaud@epitech.net>
## 
## Started on  Mon Jan 30 14:34:38 2017 ferchaud kevin
## Last update Thu Feb  2 20:53:40 2017 ferchaud kevin
##

NAME	=	navy

SRC	=	main.c			\
		main2.c			\
		main3.c			\
		main4.c			\
		main5.c			\
		main6.c			\
		main7.c			\
		error.c			\
		error2.c		\
		error3.c		\
		my_strdup.c		\
		get_next_line.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -f

LIB	=	-L lib/my/ -lmy

CFLAGS	=	-I include

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
