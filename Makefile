NAME = fillit

SRC = main.c check_input.c extra_functions.c printing.c record_fig.c solving.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	gcc -Wall -Wextra -Werror -c  $(SRC) 

clean:
	rm -f main.o check_input.o extra_functions.o printing.o record_fig.o solving.o
fclean: clean
	rm -f $(NAME)
re: fclean all
