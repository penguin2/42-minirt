NAME			=	miniRT
NAME_BONUS		=	miniRT_bonus
BONUS			=	bonus

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS_BONUS	=	-Wall -Wextra -Werror -DMODE=1
PRE_OPT			=	-MMD -MP
LINKER_OPT 		=	-L$(MINILIBX_DIR) -lmlx -L/usr/X11/lib -lX11 -lXext -lm
INCLUDE			=	-I$(INC_DIR) -I$(MINILIBX_DIR) -I$(shell cd $(MINILIBX_DIR) && ./configure | head -n 1 | cut -d' ' -f9)

SRC_DIR			=	./src
OBJ_DIR			=	./obj
OBJ_BONUS_DIR	=	./obj_bonus
INC_DIR			=	./inc
LIB_DIR			=	./lib
MINILIBX_DIR	=	./minilibx
TEST_MAIN_DIR	=	./test_main


LIB_HEADER		=	$(shell find lib/* -name "*.h")
LIB_HEADER_DIR	=	$(sort $(dir $(LIB_HEADER)))
INCLUDE			+=	$(patsubst %, -I./%, $(LIB_HEADER_DIR))

LIB_SRCS		=	$(shell find $(LIB_DIR)/* -name "*.c")
LIB_OBJS		=	$(patsubst %.o, $(OBJ_DIR)/%.o, $(LIB_SRCS:.c=.o))
LIB_OBJS_BONUS	=	$(patsubst %.o, $(OBJ_BONUS_DIR)/%.o, $(LIB_SRCS:.c=.o))

SRCS			=	$(shell cd $(SRC_DIR) && find * -name "*.c" -and ! -name "main*.c" -and ! -name "leaks.c")

ifeq ($(MAKECMDGOALS), test_json)
	SRCS += $(TEST_MAIN_DIR)/main_json.c
else ifeq ($(MAKECMDGOALS), test_scene)
	SRCS += $(TEST_MAIN_DIR)/main_scene.c
else ifeq ($(MAKECMDGOALS), test_scene_to_json)
	SRCS += $(TEST_MAIN_DIR)/main_scene_to_json.c
else ifeq ($(MAKECMDGOALS), test_scene_to_json_bonus)
	SRCS += $(TEST_MAIN_DIR)/main_scene_to_json.c
else ifeq ($(MAKECMDGOALS), test_rt)
	SRCS += $(TEST_MAIN_DIR)/main_rt.c
else ifeq ($(MAKECMDGOALS), test_rt_bonus)
	SRCS += $(TEST_MAIN_DIR)/main_rt.c
else
	SRCS += main.c
endif

OBJS			=	$(patsubst %.o, $(OBJ_DIR)/%.o, $(SRCS:.c=.o))
OBJS			+=	$(LIB_OBJS)
DEPS			=	$(OBJS:.o=.d)
OBJ_SUBDIRS 	=	$(sort $(dir $(OBJS)))

OBJS_BONUS		=	$(patsubst %.o, $(OBJ_BONUS_DIR)/%.o, $(SRCS:.c=.o))
OBJS_BONUS		+=	$(LIB_OBJS_BONUS)
DEPS_BONUS		=	$(OBJS_BONUS:.o=.d)
OBJ_BONUS_SUBDIRS 	=	$(sort $(dir $(OBJS_BONUS)))

RM				=	rm -rf 



$(OBJ_SUBDIRS) : % :
	@mkdir -p $@
	
$(OBJ_BONUS_SUBDIRS) : % :
	@mkdir -p $@

$(LIB_OBJS) : $(OBJ_DIR)/%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) $(PRE_OPT) -o $@ -c $<

$(LIB_OBJS_BONUS) : $(OBJ_BONUS_DIR)/%.o : %.c
	$(CC) $(CFLAGS_BONUS) $(INCLUDE) $(PRE_OPT) -o $@ -c $<

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) $(PRE_OPT) -o $@ -c $<

$(OBJ_BONUS_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS_BONUS) $(INCLUDE) $(PRE_OPT) -o $@ -c $<

$(NAME) : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -o$@

$(NAME_BONUS) : $(MINILIBX_DIR) $(OBJ_BONUS_SUBDIRS) $(OBJS_BONUS)
	$(CC) $(CFLAGS_BONUS) $(OBJS_BONUS) $(INCLUDE) $(LINKER_OPT) -o$@

$(MINILIBX_DIR) :
	git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR)
	make -C $(MINILIBX_DIR)

$(BONUS) : $(NAME_BONUS)

OK_OR_KO	=	"KO"
TEST_SH		=	"./test/test.sh"
JSON		=	"json"
SCENE		=	"scene"
SCENE_TO_JSON	= "scene_to_json"
SCENE_TO_JSON_BONUS	= "scene_to_json_bonus"
RT			=	"rt"
RT_BONUS	=	"rt_bonus"
# SRCS		+=	$(TEST_MAIN_DIR)/leaks.c

test_json : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -ominiRT
	$(TEST_SH) $(OK_OR_KO) $(JSON)

test_scene : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -ominiRT
	$(TEST_SH) $(OK_OR_KO) $(SCENE)

test_rt : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -ominiRT
	$(TEST_SH) $(OK_OR_KO) $(RT)

test_rt_bonus : $(MINILIBX_DIR) $(OBJ_BONUS_SUBDIRS) $(OBJS_BONUS)
	$(CC) $(CFLAGS_BONUS) $(OBJS_BONUS) $(INCLUDE) $(LINKER_OPT) -ominiRT_bonus
	$(TEST_SH) $(OK_OR_KO) $(RT_BONUS)

test_scene_to_json : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -ominiRT
	$(TEST_SH) $(OK_OR_KO) $(SCENE_TO_JSON)

test_scene_to_json_bonus : $(MINILIBX_DIR) $(OBJ_BONUS_SUBDIRS) $(OBJS_BONUS)
	$(CC) $(CFLAGS_BONUS) $(OBJS_BONUS) $(INCLUDE) $(LINKER_OPT) -ominiRT_bonus
	$(TEST_SH) $(OK_OR_KO) $(SCENE_TO_JSON_BONUS)

.PHONY	:	norm
norm :
	norminette $(SRC_DIR) $(INC_DIR) $(LIB_DIR)

.DEFAULT_GOAL	=	all
.PHONY	:	all
all		:	$(NAME)

.PHONY	:	clean
clean	:
	$(RM) $(OBJ_DIR)
	$(RM) $(OBJ_BONUS_DIR)

.PHONY	:	fclean 
fclean	:	clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

.PHONY	:	re
re		:	fclean all

-include $(DEPS) $(DEPS_BONUS)
