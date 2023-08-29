CC=c++

NAME=Fixed

SRCS = main.cpp Fixed.cpp

FLAGS=-Wall -Wextra -Werror -std=c++98

all:$(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -rf Fixed

.Phony: clean all