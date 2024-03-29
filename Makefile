##		SOURCE FILES	###
HEADER		= 	./inc/main.h
BUILD_DIR	=	./build
SRC_DIR		=	./src
GNL_DIR		=	./src/gnl
vpath %.c ${SRC_DIR} ${GNL_DIR}

SRCS 		=	main.c utils.c read_dico.c\
				get_next_line.c get_next_line_utils.c
OBJS		=	${SRCS:%.c=$(BUILD_DIR)/%.o}

###		DEFINITIONS		###
NAME		=	anag
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3

###		RULES		###
$(BUILD_DIR)/%.o: %.c
			@mkdir -p $(dir $@)
			@echo "\033[32m\c"
			${CC} ${CFLAGS} -c $< -o $@
			@echo "\033[0m\c"

all:		${NAME}

${NAME}:	${OBJS} ${HEADER}
			@echo "\033[32m\c"
			${CC} -o ${NAME} ${OBJS} ${LDFLAGS}
			@echo "Link complete for exec --> \033[4;36;1m${NAME}\033[0m"

clean:
			@rm -rf ${BUILD_DIR}
			@echo "\033[32m${NAME} obj cleaned\033[m"

fclean:		clean
			@rm -rf ${NAME}
			@echo "\033[32m${NAME} fcleaned\033[m"

re:			fclean all

.PHONY:		all clean fclean re
