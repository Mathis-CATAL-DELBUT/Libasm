NAME = libasm.a

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS = $(addprefix obj/,$(SRCS:.s=.o)) 

CC = cc
NASM = nasm
CFLAGS = -Wall -Wextra -Werror
LIB = -L. -lasm


all: obj $(NAME)

obj:
	mkdir -p obj

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

obj/%.o: %.s
	$(NASM) -felf64 -o $@ $<

main: obj $(NAME)
	$(CC) $(CFLAGS) -o main main.c $(LIB)

clean:
	rm -rf obj libasm.h.gch .gdb_history peda-session-main.txt

fclean: clean
	rm -f $(NAME) libasm main

re: fclean all

.PHONY: all clean fclean re main
