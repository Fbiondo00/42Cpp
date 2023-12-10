NAME				:=		Weapon

SRCS				:=		./Weapon.cpp \
							./HumanA.cpp \
							./HumanB.cpp \
							./main.cpp

OBJS				:=		${SRCS:.cpp=.o}

CC					:=		c++

FLAG_WARNING		:=		-Wall -Wextra -Werror -std=c++98
FLAG_INC			:= 		-I.
FLAG_DEBUG			:= 		-g
FLAGS_COMP			:= 		$(FLAG_WARNING) $(FLAG_INC) $(FLAG_DEBUG)

FLAG_MEM_LEAK		:= 		-fsanitize=address

RM					:=		rm -rf

# Color Code and template code
_YELLOW				:=		\e[38;5;184m
_GREEN				:=		\e[38;5;46m
_RESET				:=		\e[0m
_ESCK				:=		[$(_YELLOW)beccate sto cigno$(_RESET)]
_INFO				:=		[$(_YELLOW)entraaaaaa??$(_RESET)]
_SUCCESS			:=		[$(_GREEN)non entra$(_RESET)]

all:						init $(NAME)
							@ printf "$(_SUCCESS) Compilation done\n"

init:
							@ printf "$(_INFO) Initialize $(NAME)\n"

$(NAME):					$(OBJS)
							@ $(CC) $(FLAGS_COMP) -o $@ $(OBJS)

.cpp.o:
							@ $(CC) $(FLAGS_COMP) -c $< -o $@

clean:
							@ $(RM) $(OBJS)
							@ printf "$(_ESCK) Deleted files and directory\n"

fclean:						clean
							@ $(RM) $(NAME)

re:							fclean all