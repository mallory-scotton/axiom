# Basic Makefile

CC = g++

NAME = renderer

FLAG = -lsfml-window \
       -lsfml-graphics \
	   -lsfml-system \
	   -lGL \
	   -I../../include

SOURCE = ./main.cpp

$(NAME): build

clean:
	find -type f -iname "*.o" -delete
	find -type f -iname "*.a" -delete

fclean: clean
	rm -rf renderer

build:
	make -C ../.. restatic
	$(CC) -o $(NAME) $(SOURCE) ../../build/libaxiom.a $(FLAG)

re: fclean build

.PHONY: build re clean fclean
