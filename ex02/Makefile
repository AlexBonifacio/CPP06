
CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98 -MMD -MP -Wno-conversion 

OBJ_DIR = obj
SRCS = main.cpp Base.cpp

OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))
DEP = $(OBJS:.o=.d)

NAME = ex02.out

all : $(NAME)

$(NAME) : $(OBJS) Makefile
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

-include $(DEP)