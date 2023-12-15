#..............................TARGET..................................#

NAME = RPN

#..............................COMMANDS................................#

CXX = c++

CXXFLAG = -Werror -Wall -Wextra -std=c++98 -g

DFLAG = -MMD -MP

MKDIR = mkdir -p

RM   = rm -f

#...............................PATH.....................................#

SRC_DIR  = srcs/

HEADER_DIR  = includes/

OBJ_DIR    = obj/

#................................SOURCES.................................#

SRCS = main.cpp RPN.cpp
ALL_SRCS = $(addprefix $(SRC_DIR), $(SRCS))
OBJS_NAMES	= $(ALL_SRCS:.cpp=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJS_NAMES))
DEPS		= $(addprefix $(OBJ_DIR), $(ALL_SRCS:.cpp=.d))

#..................................HEADER................................#

HEADERS = $(wildcard $(HEADER_DIR)*.hpp)
HEADERS_INC	= $(addprefix -I, $(HEADER_DIR))

#...................................MAKEFILE.............................#

all: $(NAME)

$(NAME): $(HEADERS) $(OBJ)
	$(CXX) $(CXXFLAG) $(HEADERS_INC) $(OBJ) -o $@

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)$(SRC_DIR)
	$(CXX) $(CXXFLAG) $(DFLAG) -c $< -o $@

clean :
	$(RM) -r $(OBJ_DIR)

fclean : clean
		$(RM) $(NAME)

re : fclean all

# Include all .d files
-include $(DEPS)

.PHONY : all clean fclean re