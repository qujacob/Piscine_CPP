NAME = 		megaphone

# SRCDIR = 	./srcs/
# OBJDIR =	./objs/
# INCDIR =	./includes/

SRCS =		megaphone.cpp

# INCLUDES = -I$(INCDIR)
OBJS =		$(SRCS:.cpp=.o)
# OBJS :=		$(addprefix $(OBJDIR), $(OBJS))

CC = 		c++
FLAGS =		-Wall -Wextra -Werror -std=c++98
RM =		rm -rf
MKDIR =		mkdir -p

all : $(NAME)
	@echo "$(NAME) created !\n"

%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "compiling $<..."

$(NAME) : $(OBJS)
	@echo "\n=============================================\n"
	@$(CC) $(FLAGS) $(OBJS) -o $@
	@echo "Creating $@..."
	@echo "\n=============================================\n"

clean:
	@$(RM) $(OBJS)
	@echo "deleting objects..."

fclean:	clean
	@echo "\n"
	@$(RM) $(NAME)
	@echo "deleting $(NAME)..."
	@echo "\n=============================================\n"

re : fclean all

.PHONY: all clean fclean re
