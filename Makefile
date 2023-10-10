CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
PRE_OPT			=	-MMD -MP
INCLUDE			=	-I$(INC_DIR)

SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./inc

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

$(NAME) : $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -o$@

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
