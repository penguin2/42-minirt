NAME			=	miniRT

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

SRCS			=	$(shell cd $(SRC_DIR) && find * -name "*.c")

OBJS			=	$(patsubst %.o, $(OBJ_DIR)/%.o, $(SRCS:.c=.o))
OBJS			+=	$(LIB_OBJS)
DEPS			=	$(OBJS:.o=.d)

OBJ_SUBDIRS 	=	$(sort $(dir $(OBJS)))

RM				=	rm -rf 

ifdef BONUS
	CFLAGS	+=	-D MODE=1
endif

ifdef JSON
	CFLAGS	+=	-D MODE=2
endif

ifdef SCENE
	CFLAGS	+=	-D MODE=3
endif



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

norm :
	norminette $(SRC_DIR) $(INC_DIR) $(LIB_DIR)

bonus :
	make BONUS=1

test_json :
	make JSON=1

test_scene :
	make SCENE=1

json :
	./test/json_to_json_object/test.sh

scene :
	./test/json_object_to_scene/test.sh

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
