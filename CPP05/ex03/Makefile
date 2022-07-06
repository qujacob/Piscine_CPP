NAME = 		Intern

SRCDIR = 	./srcs/
OBJDIR =	./objs/
INCDIR =	./includes/

SRCS =		main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

INCS = -I$(INCDIR)
OBJS =		$(SRCS:.cpp=.o)
OBJS :=		$(addprefix $(OBJDIR), $(OBJS))

CC = 		c++
FLAGS =		-Wall -Wextra -Werror -std=c++98 $(INCS)
RM =		rm -rf
MKDIR =		mkdir -p

all : $(NAME)
	@echo "$(NAME) created !\n"

$(OBJDIR)%.o : $(SRCDIR)%.cpp
	@$(MKDIR) $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "compiling $<..."

$(NAME) : $(OBJS)
	@echo "\n=============================================\n"
	@$(CC) $(FLAGS) $(OBJS) -o $@
	@echo "Creating $@..."
	@echo "\n=============================================\n"


clean :
	@$(RM) $(OBJDIR)
	@echo "deleting objects..."

fclean : clean
	@echo "\n"
	@$(RM) $(NAME)
	@echo "deleting $(NAME)..."
	@echo "\n=============================================\n"

re : fclean all

.PHONY: all clean fclean re mk
