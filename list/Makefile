COMPILER=clang
FLAGS=-Wall -g -o
NAME=list

.PHONY: all
all: main.out

.PHONY: clean
clean:
	rm -f *.o

main.out: main.o $(NAME).o
	clang $(FLAGS) $@ $^

main.o: main.c
	clang -c $< $(FLAGS) $@

$(NAME).o: $(NAME).c $(NAME).h
	clang -c $< $(FLAGS) $@
