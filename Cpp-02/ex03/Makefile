NAME = BSP
CXX = c++
CXXFLAGS= -Wall -Wextra -Werror --std=c++98

SRCS = main.cpp Fixed.cpp Point.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Fixed.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean :
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
