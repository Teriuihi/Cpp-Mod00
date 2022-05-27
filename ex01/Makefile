NAME=ex01
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c++98
RM=rm -f

FILES=main.cpp PhoneBook.cpp Contact.cpp
FILES_OBJ=$(FILES:%.cpp=%.o)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(FILES_OBJ) -lstdc++

clean:
	$(RM) $(FILES_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: make all clean fclean re
