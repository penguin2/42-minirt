NAME		=	libft.a
CC			=	cc
AR			=	ar crs
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=  \
				ft_calloc.c \
				ft_xcalloc.c \
				ft_memcpy.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_strlen.c \
				ft_vla_init.c \
				ft_vla_append.c \
				ft_vla_free.c
OBJS		=	$(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
