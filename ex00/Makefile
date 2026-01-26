

CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98 -Wno-conversion -Iinc -MMD -MP

OBJ_DIR = obj

SRCS = main.cpp ScalarConverter.cpp
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEP = $(OBJS:.o=.d)

NAME = ex00.out

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
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re

-include $(DEP)