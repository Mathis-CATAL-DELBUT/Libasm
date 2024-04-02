NAME = libasm.a

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s \
       ft_strdup.s
SRCS_BONUS = 	ft_atoi_base.s ft_list_push_front.s ft_list_size.s \
				ft_list_sort.s ft_strlen.s
OBJS = $(addprefix obj/,$(SRCS:.s=.o))
OBJS_BONUS = $(addprefix obj_bonus/,$(SRCS_BONUS:.s=.o))

CC = cc
NASM = nasm
CFLAGS = -Wall -Wextra -Werror
LIB = -L. -lasm

all: obj $(NAME)

obj:
	mkdir -p obj

obj_bonus:
	mkdir -p obj_bonus

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

obj/%.o: %.s
	$(NASM) -felf64 -o $@ $<

obj_bonus/%.o: %.s
	$(NASM) -felf64 -o $@ $<

bonus: obj_bonus $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

main: obj $(NAME)
	$(CC) $(CFLAGS) -o main main.c $(LIB)

main_bonus: $(OBJS_BONUS) main_bonus.c
	$(CC) $(CFLAGS) -o main_bonus main_bonus.c $(LIB)

clean:
	rm -rf obj obj_bonus libasm.h.gch .gdb_history \
	peda-session-main.txt peda-session-main_bonus.txt

fclean: clean
	rm -f $(NAME) libasm main main_bonus 

re: fclean all

.PHONY: all clean fclean re main bonus
