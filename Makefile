##		SOURCE FILES	###
HEADER		= 	./inc/main.hpp
BUILD_DIR	=	./build
SRC_DIR		=	./src
vpath %.cpp ${SRC_DIR}

SRCS 		=	main.cpp Dico.cpp utils.cpp
OBJS		=	${SRCS:%.cpp=$(BUILD_DIR)/%.o}

###		DEFINITIONS		###
NAME		=	anag
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -g3

###		RULES		###
$(BUILD_DIR)/%.o: %.cpp
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
