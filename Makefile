
NAME = printf

SRC = *.c

all: $(NAME)

$(NAME): ${INCL}
	gcc -g $(SRC)

clean:
	rm -rf $(NAME)

re: clean all
