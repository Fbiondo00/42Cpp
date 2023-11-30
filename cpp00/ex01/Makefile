NAME				:=		phone_book

# List of sources
SRCS				:=		./main.cpp			\
								./Contact.cpp	\
								./PhoneBook.cpp 
OBJS				:=		${SRCS:.cpp=.o}

# Compiler
CC					:=		c++

# Flags - compilation
FLAG_WARNING		:=		-Wall -Wextra -Werror -std=c++98
FLAG_INC			:= 		-I.
FLAG_DEBUG			:= 		-g
FLAGS_COMP			:= 		$(FLAG_WARNING) $(FLAG_INC) $(FLAG_DEBUG)

# Flags - memory leak check
FLAG_MEM_LEAK		:= 		-fsanitize=address

# Others commands
RM					:=		rm -rf

# Color Code and template code
_YELLOW				:=		\e[38;5;184m
_GREEN				:=		\e[38;5;46m
_RESET				:=		\e[0m
_INFO				:=		[$(_YELLOW)INFO$(_RESET)]
_SUCCESS			:=		[$(_GREEN)SUCCESS$(_RESET)]

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
							@ printf "$(_INFO) Deleted files and directory\n"

fclean:						clean
							@ $(RM) $(NAME)

re:							fclean all

debug:						FLAGS_COMP += $(FLAG_MEM_LEAK)
debug:						re


.PHONY:						all clean fclean re