CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
PRE_OPT			=	-MMD -MP
LINKER_OPT 		=	-L$(MINILIBX_DIR) -lmlx -L/usr/X11/lib -lX11 -lXext -lm
INCLUDE			=	-I$(INC_DIR) -I$(MINILIBX_DIR) -I$(shell cd $(MINILIBX_DIR) && ./configure | head -n 1 | cut -d' ' -f9)

LIB_HEADER		=	$(shell find lib/* -name "*.h")
LIB_HEADER_DIR	=	$(sort $(dir $(LIB_HEADER)))
INCLUDE			+=	$(patsubst %, -I./%, $(LIB_HEADER_DIR))

SRC_DIR			=	./src
OBJ_DIR			=	./obj
INC_DIR			=	./inc
MINILIBX_DIR	=	./minilibx

NAME			=	miniRT

#(cd src && find * -name "*.c")
SRCS			=	$(shell cd src && find * -name "*.c")

OBJS		=	$(patsubst %.o, $(OBJ_DIR)/%.o, $(SRCS:.c=.o))
OBJ_SUBDIRS =	$(sort $(dir $(OBJS)))
DEPS		=	$(OBJS:.o=.d)

RM			=	rm -rf 

$(OBJ_SUBDIRS) : % :
	@mkdir -p $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) $(PRE_OPT) -o $@ -c $<

$(NAME) : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -o$@

$(MINILIBX_DIR) :
	git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR)
	make -C $(MINILIBX_DIR)

.DEFAULT_GOAL	=	all
.PHONY	:	all
all		:	$(NAME)

.PHONY	:	clean
clean	:
	$(RM) $(OBJ_DIR)

.PHONY	:	fclean 
fclean	:	clean
	$(RM) $(NAME)

.PHONY	:	re
re		:	fclean all

-include $(DEPS)
