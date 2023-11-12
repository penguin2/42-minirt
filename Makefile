NAME			=	miniRT
BONUS			=	bonus

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
PRE_OPT			=	-MMD -MP
LINKER_OPT 		=	-L$(MINILIBX_DIR) -lmlx -L/usr/X11/lib -lX11 -lXext -lm
INCLUDE			=	-I$(INC_DIR) -I$(MINILIBX_DIR) -I$(shell cd $(MINILIBX_DIR) && ./configure | head -n 1 | cut -d' ' -f9)

SRC_DIR			=	./src
OBJ_DIR			=	./obj
INC_DIR			=	./inc
LIB_DIR			=	./lib
MINILIBX_DIR	=	./minilibx


LIB_HEADER		=	$(shell find lib/* -name "*.h")
LIB_HEADER_DIR	=	$(sort $(dir $(LIB_HEADER)))
INCLUDE			+=	$(patsubst %, -I./%, $(LIB_HEADER_DIR))
LIB_SRCS		=	$(shell find $(LIB_DIR)/* -name "*.c")
LIB_OBJS		=	$(patsubst %.o, $(OBJ_DIR)/%.o, $(LIB_SRCS:.c=.o))

SRCS			=	$(shell cd $(SRC_DIR) && find * -name "*.c" -and ! -name "main*.c")

ifeq ($(MAKECMDGOALS), test_json)
	SRCS += main_json.c
else ifeq ($(MAKECMDGOALS), test_scene)
	SRCS += main_scene.c
else ifeq ($(MAKECMDGOALS), $(BONUS))
	SRCS += main.c
	CFLAGS += -DMODE=1
else
	SRCS += main.c
endif

OBJS			=	$(patsubst %.o, $(OBJ_DIR)/%.o, $(SRCS:.c=.o))
OBJS			+=	$(LIB_OBJS)
DEPS			=	$(OBJS:.o=.d)

OBJ_SUBDIRS 	=	$(sort $(dir $(OBJS)))

RM				=	rm -rf 

$(OBJ_SUBDIRS) : % :
	@mkdir -p $@

$(LIB_OBJS) : $(OBJ_DIR)/%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) $(PRE_OPT) -o $@ -c $<

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) $(PRE_OPT) -o $@ -c $<

$(NAME) : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -o$@

$(MINILIBX_DIR) :
	git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR)
	make -C $(MINILIBX_DIR)

$(BONUS) : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -o$(NAME)
	@touch $@

test_json : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -ominiRT
	./test/json_to_json_object/test.sh

test_scene : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -ominiRT
	./test/json_object_to_scene/test.sh

norm :
	norminette $(SRC_DIR) $(INC_DIR) $(LIB_DIR)

.DEFAULT_GOAL	=	all
.PHONY	:	all
all		:	$(NAME)

.PHONY	:	clean
clean	:
	$(RM) $(OBJ_DIR)

.PHONY	:	fclean 
fclean	:	clean
	$(RM) $(NAME)
	$(RM) $(BONUS)

.PHONY	:	re
re		:	fclean all

-include $(DEPS)
