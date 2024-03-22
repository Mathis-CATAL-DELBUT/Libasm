NAME = libasm.a
SRCS_ASM_LIB = coucou.s str_len.s
SRCS_ASM_MAIN = main.s
OBJS_ASM = $(addprefix obj/,$(SRCS_ASM_LIB:.s=.o))
OBJ_MAIN = obj/main.o
PTO = obj/*.o

NASM = nasm
RM = rm -rf
LD = ld
LD_FLAGS = -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2

all: $(NAME)

obj/%.o : %.s
	mkdir -p obj && $(NASM) -f elf64 -g $< -o $@

$(NAME): $(OBJS_ASM)
	ar rcs $(NAME) $(OBJS_ASM)

$(OBJ_MAIN): $(SRCS_ASM_MAIN)
	mkdir -p obj && $(NASM) -f elf64 -g $< -o $@

clean:
	$(RM) $(OBJS_ASM) $(PTO) obj

fclean: clean
	$(RM) $(NAME) libasm

launch: $(NAME) $(OBJ_MAIN)
	$(NASM) -f elf64 $(SRCS_ASM_MAIN) -o $(OBJ_MAIN)
	$(LD) $(OBJ_MAIN) $(OBJS_ASM) -L. -lasm $(LD_FLAGS) -o libasm

re : fclean $(NAME)

.PHONY: all clean fclean re launch
