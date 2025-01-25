NAME = Zombie
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS=main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS=$(SRCS:.cpp=.o)


$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all :$(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re: fclean all