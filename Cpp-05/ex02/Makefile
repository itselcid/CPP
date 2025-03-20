NAME = AForm
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS=main.cpp  GradeTooHighException.cpp GradeTooLowException.cpp FormNotSignedException.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp AForm.cpp 

OBJS=$(SRCS:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all